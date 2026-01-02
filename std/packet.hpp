#pragma once
#include<new>
#include<utility>
#include "lib::egress_buffer.hpp"
#include<cassert>

struct packet{
    
  std::uint64_t id;
  std::uint32_t src_ip;
  std::uint32_t dest_ip;
  std::uint16_t src_port;
  std::uint16_t dest_port;
  
  enum l4_proto : std::uint8_t{
    tcp,udp,icmp,other}proto;

  std::uint8_t dscp;
  
  std::uint64_t timestamp;
  std::uint64_t byte_size;
};
