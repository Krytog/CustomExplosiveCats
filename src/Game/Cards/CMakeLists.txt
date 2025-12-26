add_library(game_cards
    BaseCard.cpp
)

target_include_directories(game_cards PRIVATE ${BASE_SRC_PATH})
