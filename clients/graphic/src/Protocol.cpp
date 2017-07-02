#include "Protocol.hpp"

const std::map<Protocol::Cmd, std::string> Protocol::cmdMap = {
  {Cmd::MSZ, "msz"},
  {Cmd::BCT, "bct"},
  {Cmd::TNA, "tna"},
  {Cmd::PNW, "pnw"},
  {Cmd::SGT, "sgt"}
};

const std::map<std::string, Protocol::Cmd> Protocol::cmdString = {
  {"msz", Cmd::MSZ},
  {"bct", Cmd::BCT},
  {"tna", Cmd::TNA},
  {"pnw", Cmd::PNW},
  {"sgt", Cmd::SGT}
};

const std::map<Protocol::Cmd, std::function<void(Logic&, std::string const&)>> Protocol::cmdFun = {
  {Cmd::MSZ, &msz},
  {Cmd::BCT, &bct},
  {Cmd::TNA, &tna},
  {Cmd::PNW, &pnw},
  {Cmd::SGT, &sgt}
};

Protocol::Cmd Protocol::stringToCmd(std::string const& str) {
  if (cmdString.count(str) > 0) {
    return cmdString.at(str);
  } else {
    return Cmd::UNKNOWN;
  }
}

std::string Protocol::cmdToString(Cmd res) {
  if (cmdMap.count(res) > 0) {
    return cmdMap.at(res);
  } else {
    return "";
  }
}

void Protocol::initDataGame(Logic& l) {
  Network::getInstance().sendMsg("GRAPHIC");
  std::string line = Network::getInstance().recvMsg();

  while (!line.empty()) {
    std::cout << "Line: " << line << std::endl;
  std::stringstream ss(line);
  std::string cmdString;

  cmdString = Tools::parseStreamString(ss);
  std::cout << "Command: " << cmdString << std::endl;

  Protocol::Cmd cmd = Protocol::stringToCmd(cmdString);
  std::cout << "Enum cmd: " << cmd << std::endl;

  Protocol::cmdFun.at(cmd)(l, line);
  line = Network::getInstance().recvMsg(MSG_DONTWAIT);
  }
}

void Protocol::msz(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  l.setMapSize(coord);
}

void Protocol::bct(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  resource_list	rl = {
    {
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
    }
  };
  l.setMapContent(coord, rl);
}

void Protocol::tna(Logic& l, std::string const& str) {
  
}

void Protocol::pnw(Logic& l, std::string const& str) {
  
}

void Protocol::sgt(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  int t;
  ss >> t;
  l.setUnitTime(t);
}
