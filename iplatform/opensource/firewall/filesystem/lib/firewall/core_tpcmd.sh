# tpsdk专有功能 by huluyao 20140423

fw_load_tpcmd() {    
    # for guest_network
    local rule="-p tcp -m multiport --ports 80,443,22,20002"
    fw add 4 f block_entry_list
    fw add 4 f zone_lan block_entry_list 1 { "$rule" }
    fw add 4 f ftp_access
    fw add 4 f zone_wan ftp_access 1
    fw add 4 f ftp_access_lan
    fw add 4 f zone_lan ftp_access_lan 1

    # for local management
    fw add 4 f local_mgnt
    fw add 4 f local_mgnt DROP

    # for remote management
    fw add 4 f lan_remote_mgnt
    fw add 4 f input_lan lan_remote_mgnt
}

