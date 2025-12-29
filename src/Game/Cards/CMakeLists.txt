add_library(ec_game_cards
    BaseCard.cpp
    ExplosiveCatCard.cpp
    DefuseCard.cpp
    DenyCard.cpp
    FutureGlanceCard.cpp
    CatCard.cpp
)

target_include_directories(ec_game_cards PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_game_cards PRIVATE
    ec_game_entities
    ec_game_runtime
    ec_game_cardutilities
)

target_link_libraries(ec_game_cards PUBLIC
    mols_includes
)
