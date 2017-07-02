#ifndef LOGIC_HPP_
# define LOGIC_HPP_

# include <SFML/Graphics.hpp>
# include <string>
# include <sstream>
# include <vector>
# include <map>
# include "AudioHandler.hpp"
# include "ImageHandler.hpp"
# include "TileMap.hpp"
# include "Player.hpp"
# include "Egg.hpp"
# include "Resource.hpp"
# include "Team.hpp"
# include "Protocol.hpp"

# include <iostream>

# define CAM_SPEED 10

class				Logic
{
private:
  sf::Vector2i				_resolution;
  sf::Vector2i				_map_size;
  sf::RenderWindow			_window;
  sf::View				_view;
  TileMap				_map;
  std::map<unsigned int, Player*>	_players;
  std::map<unsigned int, Egg*>		_eggs;
  std::map<std::string, Team*>		_teams;
  int					_unitTime;

public:
  Logic(sf::Vector2i const&, std::string const& = "Zappy");
  ~Logic();

  void			createMap(TileMap::Terrain);
  void			createPlayer(unsigned int const, sf::Vector2i const&, unsigned int const, unsigned int const, std::string const&);
  void			createEgg(unsigned int const, unsigned int const, sf::Vector2i const&);

  void			eventLoop();
  bool			isOpen() const;
  void			updateData();
  void			clear();
  void			display();

  void			setMapSize(sf::Vector2i const&);
  void			setMapContent(sf::Vector2i const&, resource_list);
  void			setUnitTime(int);
  void		        addTeam(std::string const&);
  void			setPlayerPosition(unsigned int const, sf::Vector2i const&, unsigned int const);
  void			setPlayerLevel(unsigned int const, unsigned int const);

  void			playerDropResource(unsigned int const, unsigned int const);
  void			playerTakeResource(unsigned int const, unsigned int const);
  void			playerDead(unsigned int const);

  void			endGame(std::string const&);

  void			update();
};

#endif /* !LOGIC_HPP_ */
