cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(main)

# Находит и подключает SFML
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

# Добавляет исполняемый файл main с исходниками
add_executable(main main.cpp players.cpp players.hpp engine.cpp engine.hpp updata.cpp draw.cpp input.cpp enemy.cpp enemy.hpp interaction.cpp)

# Линкует библиотеки SFML
target_link_libraries(main sfml-graphics sfml-window sfml-system)
