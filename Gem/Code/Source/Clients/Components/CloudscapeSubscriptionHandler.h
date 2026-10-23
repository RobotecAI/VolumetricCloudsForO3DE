#pragma once

#include <ROS2Controllers/RobotControl/ControlSubscriptionHandler.h>
#include <std_msgs/msg/float32.hpp>

namespace VolumetricClouds
{
    class CloudscapeSubscriptionHandler : public ROS2Controllers::ControlSubscriptionHandler<std_msgs::msg::Float32>
    {
    public:
        using MessageCallback = AZStd::function<void(const std_msgs::msg::Float32&)>;

        explicit CloudscapeSubscriptionHandler(MessageCallback messageCallback);

    private:
        // ROS2Controllers::ControlSubscriptionHandler overrides
        void SendToBus(const std_msgs::msg::Float32& message) override;

        MessageCallback m_messageCallback;
    };
} // VolumetricClouds
