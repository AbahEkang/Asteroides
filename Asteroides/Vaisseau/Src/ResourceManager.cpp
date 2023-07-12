#include "ResourceManager.h"
#include <iostream>

std::unordered_map<std::string_view, sf::Texture> Resources::ResourceManager::resources{};

sf::Texture const& Resources::ResourceManager::GetResource(std::string_view const& image)
{
	// TODO: insert return statement here

	if (resources.find(image) == resources.end())
	{
		if (!resources[image].loadFromFile(image.data())) {
			std::cerr << "Can't load texture: " << image << std::endl;
		}

		return resources[image];
	}

	return resources[image];
}
