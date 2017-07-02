#ifndef IMAGEHANDLER_HPP_
# define IMAGEHANDLER_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <tuple>
# include <memory>

class					ImageHandler
{
public:
  enum					Texture { PLAYER, RESOURCE, MAP };

private:
  ImageHandler();

  std::map<Texture, std::tuple<sf::Texture, sf::Vector2i>>	_textures;
  static std::unique_ptr<ImageHandler>				_instance;

public:
  ~ImageHandler();

  static ImageHandler			&getInstance();
  static void			        initImageHandler();

  sf::Texture				getTexture(Texture);
  sf::Vector2i const			&getSetSize(Texture);
};

#endif /* !IMAGEHANDLER_HPP_ */
