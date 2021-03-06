file(COPY data DESTINATION .)

# ----------- IMUGPSFusionTest

add_executable(IMUGPSFusionTest
    src/IMUGPSFusionTest.cpp
)

target_link_libraries(IMUGPSFusionTest
    ROAMestimation
)


# ----------- IMUHandlerFusionTest

add_executable(IMUHandlerFusionTest
    src/IMUHandlerFusionTest.cpp
)

target_link_libraries(IMUHandlerFusionTest
    ROAMestimation ROAMimu 
)

# ----------- PerfectIMUHandlerTest

add_executable(PerfectIMUHandlerTest
    src/PerfectIMUHandlerTest.cpp
)

target_link_libraries(PerfectIMUHandlerTest
    ROAMestimation ROAMimu 
)


# ----------- PerfectIMUTest

add_executable(PerfectIMUTest
    src/PerfectIMUTest.cpp
)

target_link_libraries(PerfectIMUTest
    ROAMestimation ROAMimu 
)

# ----------- PerfectIMUInEarthFrameTest

add_executable(PerfectIMUInEarthFrameTest
    src/PerfectIMUInEarthFrameTest.cpp
)

target_link_libraries(PerfectIMUInEarthFrameTest
    ROAMestimation ROAMimu 
)

# ----------- CameraIMUTest

add_executable(CameraIMUTest
    src/CameraIMUTest.cpp
)

target_link_libraries(CameraIMUTest
    ROAMestimation ROAMimu ROAMvision
)

# ----------- TestPoseGetters

add_executable(TestPoseGetters
    src/TestPoseGetters.cpp
)

target_link_libraries(TestPoseGetters
    ROAMestimation
)

# ----------- TestInterpolatingEdge

add_executable(TestInterpolatingEdge
    src/TestSE3InterpolationEdge.cpp
)

target_link_libraries(TestInterpolatingEdge
    ROAMestimation
)

