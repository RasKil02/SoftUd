cmake_minimum_required(VERSION 3.10)
project(Spil LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List all source files
set(SOURCES
    main.cpp
    Hero.cpp
    Karakter.cpp
    Fjende.cpp
    GameMaster.cpp
    GrotteFactory.cpp
    Grotte.cpp
    FjendeFactory.cpp
    Database.cpp
    Våben.cpp
)

# Add the executable
add_executable(spil ${SOURCES})

# Link against sqlite3
find_package(SQLite3 REQUIRED)
target_link_libraries(spil PRIVATE SQLite::SQLite3)
