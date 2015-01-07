/*
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-server.
 *
 * libbitcoin-server is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_SERVER_CONFIG_HPP
#define LIBBITCOIN_SERVER_CONFIG_HPP

#include <map>
#include <stdint.h>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

namespace server {

struct node_config_object
{
    std::string hostname;
    uint16_t port;
};

struct config_type
{
    typedef std::vector<node_config_object> nodes_list;
    typedef std::vector<std::string> ipaddress_list;

    std::string output_file = "debug.log";
    std::string error_file = "error.log";
    std::string blockchain_path = "blockchain/";
    std::string hosts_file = "hosts";
    std::string service = "tcp://*:9091";
    std::string heartbeat = "tcp://*:9092";
    bool publisher_enabled = false;
    std::string block_publish;
    std::string tx_publish;
    std::string certificate = "";
    ipaddress_list whitelist;
    std::string client_allowed_certs = "ALLOW_ALL_CERTS";
    std::string name;
    unsigned int outgoing_connections = 8;
    bool listener_enabled = true;
    nodes_list nodes;
    bool log_requests = false;
    unsigned int history_db_active_height = 0;
};

typedef std::map<std::string, std::string> config_map_type;
void load_config(config_type& config, 
    boost::filesystem::path& config_path);
std::string system_config_directory();

} // namespace server

#endif
