cc_library(
    name = "graph_structure",
    srcs = ["graph_structure.cc"],
    hdrs = ["graph_structure.h"],
)

cc_binary(
    name = "graph_test",
    srcs = ["graph_test.cc"],
    deps = ["//tensorflow/cc:cc_ops",
        "//tensorflow/cc:client_session",
        "//tensorflow/core:tensorflow",
	    ":graph_structure",
    ],
)

cc_library ( 
    name="node_data", 
    srcs=["node_data.cc"],
    hdrs = ["node_data.h"],
)
