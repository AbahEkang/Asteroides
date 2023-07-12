#pragma once

#include "ResourceManager.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string_view>

namespace Resources
{
	class ResourceManager
	{
	public:
		ResourceManager() = delete;
		static sf::Texture const& GetResource(std::string_view const& image);

	protected:

	private:

		static std::unordered_map<std::string_view, sf::Texture> resources;

	};


}
