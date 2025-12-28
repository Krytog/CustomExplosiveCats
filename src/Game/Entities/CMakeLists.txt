add_library(ec_game_entities
    World.cpp
)

target_include_directories(ec_game_entities PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_game_entities PRIVATE
    ec_game_cards
    ec_game_cardutilities
)
