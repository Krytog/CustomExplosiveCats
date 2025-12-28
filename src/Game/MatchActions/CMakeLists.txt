add_library(ec_game_rules
    Initialization.cpp
)

target_include_directories(ec_game_rules PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_game_rules PRIVATE
    ec_game_cards
    ec_game_cardutilities
    ec_game_entities
)

target_link_libraries(ec_game_rules PUBLIC
    mols_includes
)
