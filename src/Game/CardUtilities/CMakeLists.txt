add_library(ec_game_cardutilities
    CardCollection.cpp
    Deck.cpp
    UniformShuffler.cpp
)

target_include_directories(ec_game_cardutilities PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_game_cardutilities PRIVATE
    ec_game_cards
)

target_link_libraries(ec_game_cardutilities PUBLIC
    mols_includes
)
