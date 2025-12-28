add_executable(ec_server_mock
    main.cpp
    MockGameIO.cpp
)

target_include_directories(ec_server_mock PRIVATE ${BASE_SRC_PATH})

target_link_libraries(ec_server_mock PRIVATE
    ec_game_runtime
)

target_link_libraries(ec_game_rules PUBLIC
    mols_includes
)
