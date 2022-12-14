#
# Copyright (C) 2010-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=iputils
PKG_VERSION:=20101006
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)/Default
  SUBMENU:=IPv6
  SECTION:=ipv6
  CATEGORY:=TP-LINK iplatform apps
  TITLE:=iputils
  DEPENDS:=+PACKAGE_libopenssl:libopenssl +PACKAGE_libcyassl:libcyassl
endef

ifneq ($(CONFIG_PACKAGE_libcyassl),)
  export USE_LIB_CYASSL=1
  USELIBCYASSL=-DUSE_LIB_CYASSL -lcyassl
endif

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include \
	$(USELIBCYASSL)

define Package/$(PKG_NAME)-ping6
  $(call Package/$(PKG_NAME)/Default)
  TITLE+= ping6
  DEPENDS:=+PACKAGE_libopenssl:libopenssl +PACKAGE_libcyassl:libcyassl
endef

define Package/$(PKG_NAME)-ping6/description
	ping6 is a icmp tool for IPv6.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile	
	$(MAKE) -C $(PKG_BUILD_DIR) $(TARGET_CONFIGURE_OPTS) \
		TARGET_CFLAGS="$(TARGET_CFLAGS)" \
		all 
endef

define Package/$(PKG_NAME)-ping6/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ping6 $(1)/usr/sbin
endef

$(eval $(call BuildPackage,iputils-ping6))
