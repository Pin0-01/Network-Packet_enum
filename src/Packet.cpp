#include "../include/Packet.hpp"
#include <iostream>


using namespace std;


string Packet::getPacketTypeName() const {
  switch(type){
    case PacketType::UNKNOWN:
      return "UNKNOWN";
    case PacketType::DATA:
      return "DATA";
    case PacketType::CONTROL:
      return "CONTROL";
    case PacketType::ERROR:
      return "ERROR";
    default:
      return "UNKNOWN ERROR";
  }
}
void Packet::setType(PacketType newType) {
    type = newType;
}

string Packet::getStatusName() const {
  switch(packetStatus){
    case Status::PENDING:
      return "PENDING";
    case Status::VALID:
      return "VALID";
    case Status::INVALID:
      return "INVALID";
    case Status::TIMEOUT:
      return "TIMEOUT";
    default:
      return "Unknown Packet Status";
  }
}

string Packet::getProtocolName() {
  switch(protocol){
    case Protocol::TCP:
      return "TCP";
    case Protocol::UDP:
      return "UDP";
    case Protocol::HTTP:
      return "HTTP";
    case Protocol::FTP:
      return "FTP";
    default:
      return "Unknown Protocol";
  }
}


void Packet::validatePacket() {
  switch(type){
    case PacketType::DATA:
      if(protocol == Protocol::TCP || protocol == Protocol::UDP){
        packetStatus = Status::VALID;
        break;
      }else{
        packetStatus = Status::INVALID;
        break;
      }
    case PacketType::CONTROL:
      if(protocol == Protocol::TCP) {packetStatus = Status::VALID;
      break;
      }
      else {packetStatus = Status::INVALID; 
      break;
      }
    case PacketType::ERROR:
      packetStatus = Status::VALID;
      break;
    case PacketType::UNKNOWN:
      packetStatus = Status::INVALID;
      break;
    default:
      packetStatus = Status::INVALID;
      break;
  }
}

bool Packet::isError() {
  if(packetStatus == Status::INVALID)
    return true;
  else return false;
  
}

void Packet::displayInfo() {
  std::cout << "Packet type: "<< getPacketTypeName() << std::endl;
  std::cout << "Protocol: "<< getProtocolName() << std::endl;
  std::cout << "Status: "<< getStatusName() << std::endl;
}