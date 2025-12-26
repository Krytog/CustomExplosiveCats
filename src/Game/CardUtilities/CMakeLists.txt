add_library(game_cardutilities
    CardCollection.cpp
    Deck.cpp
)

target_include_directories(game_cardutilities PRIVATE ${BASE_SRC_PATH})

target_link_libraries(game_cardutilities PRIVATE
    BaseCard.cpp
)
