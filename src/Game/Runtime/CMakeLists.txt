add_library(ec_game_runtime
    MatchLog.cpp
    Runtime.cpp
)

target_include_directories(ec_game_runtime PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_game_runtime PRIVATE
    ec_game_cards
    ec_game_cardutilities
    ec_game_entities
)

target_link_libraries(ec_game_runtime PUBLIC
    mols_includes
)
