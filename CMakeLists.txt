cmake_minimum_required(VERSION 4.2)
project(Blackjack_cpp)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 3.0.2 COMPONENTS Graphics Window System Audio REQUIRED)

file( COPY
        ${CMAKE_SOURCE_DIR}/Assets
        DESTINATION ${CMAKE_BINARY_DIR}/
)

add_library(SFML_Boost SHARED
        Libraries/BackgroundGen.cpp Libraries/BackgroundGen.h
        Libraries/CustomErrors.cpp Libraries/CustomErrors.h
        Libraries/BasicButton.cpp Libraries/BasicButton.h
        Libraries/PlayingCard.cpp Libraries/PlayingCard.h
        Libraries/PlayersHand.cpp Libraries/PlayersHand.h
        Libraries/GameLogic.cpp Libraries/GameLogic.h
)

add_executable(Blackjack_cpp main.cpp)

target_link_libraries(Blackjack_cpp PUBLIC SFML::Graphics SFML::Window SFML::System SFML::Audio)
target_link_libraries(SFML_Boost PUBLIC SFML::Graphics SFML::Window SFML::System SFML::Audio)


target_link_libraries(Blackjack_cpp PRIVATE SFML_Boost)

