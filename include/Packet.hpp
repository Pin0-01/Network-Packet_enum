#include <string>
#include "PacketType.hpp"
#include "Protocol.hpp"
#include "Status.hpp"

using namespace std;

class Packet {
private:
  string getPacketTypeName() const;
  string getStatusName() const;
  PacketType type;
  Protocol protocol;
  Status packetStatus;
public:
  Packet(PacketType pType, Protocol prtcl) : type(pType),
  protocol(prtcl) {}
  string getProtocolName();
  void validatePacket();
  bool isError();
  void displayInfo();
  void setType(PacketType newType);
};