#
# Copyright (C) 2008-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=swconfig
PKG_RELEASE:=10

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/kernel.mk

define Package/swconfig
  SECTION:=base
  CATEGORY:=Base system
  DEPENDS:=@!TARGET_brcm47xx +libuci +libnl-tiny
  TITLE:=Switch configuration utility
endef

TARGET_CPPFLAGS := \
	-D_GNU_SOURCE \
	-I$(STAGING_DIR)/usr/include/libnl-tiny \
	-I$(LINUX_SRC_DIR)/include \
	-I$(LINUX_SRC_DIR)/arch/$(LINUX_KARCH)/include \
	-I$(PKG_BUILD_DIR) \
	$(TARGET_CPPFLAGS)

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	CFLAGS="$(TARGET_CPPFLAGS) $(TARGET_CFLAGS)" \
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(TARGET_CONFIGURE_OPTS) \
		LIBS="$(TARGET_LDFLAGS) -lnl-tiny -lm -luci"
endef

define Package/swconfig/install
	$(INSTALL_DIR) $(1)/sbin $(1)/lib/switch/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/swconfig $(1)/sbin/swconfig
	$(INSTALL_DATA) ./files/switch.sh $(1)/lib/switch/
endef

$(eval $(call BuildPackage,swconfig))
