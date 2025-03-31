cmake_minimum_required (VERSION 3.11)
project (facialrecognition)
find_package (OpenCV 4.0.0 REQUIRED)
message ("OpenCV version:  ${OpenCV_VERSION}")
include_directories (${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIR})
SET (SRC src/main.cpp
         src/image.cpp

)
ADD_EXECUTABLE (${PROJECT_NAME} ${SRC})
TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${OpenCV_LIBS})
# SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
# SET (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
