#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			Tileset,
			BG,
			Particles,
			Apple,
			WhiteFork,
			BlackFork,
			CleanJar,
			DirtyJar,
			CleanPaper,
			DirtyPaper,
			Coffee,
			Bottle,
			Count
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:     return "Bin.png";
		case eTexture::Tileset:    return "tileset.png";
		case eTexture::BG:		   return "bg.png";
		case eTexture::Particles:  return "particles.png";
		case eTexture::Apple:      return "Apple.png";
		case eTexture::WhiteFork:  return "Fork_White.png";
		case eTexture::BlackFork:  return "Fork_Black.png";
		case eTexture::CleanJar:   return "Jar_Clean.png";
		case eTexture::DirtyJar:   return "Jar_Dirty.png";
		case eTexture::CleanPaper: return "Paper_Clean.png";
		case eTexture::DirtyPaper: return "Paper_Dirty.png";
		case eTexture::Coffee:     return "Coffee.png";
		case eTexture::Bottle:     return "Bottle.png";
		default:               return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture)
		{
		case  GameEngine::eTexture::Player:  return sf::Vector2f(219, 218);
		case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::BG:	     return sf::Vector2f(800.f, 800.f);
		case  GameEngine::eTexture::Particles: return sf::Vector2f(31.f, 32.f);
		case  GameEngine::eTexture::Apple: return sf::Vector2f(50.f, 50.f);
		case  GameEngine::eTexture::WhiteFork: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::BlackFork: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::CleanJar: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::DirtyJar: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::CleanPaper: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::DirtyPaper: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::Coffee: return sf::Vector2f(50, 50);
		case  GameEngine::eTexture::Bottle: return sf::Vector2f(50, 50);
		default:							 return sf::Vector2f(-1.f, -1.f);
		}
	}
}

