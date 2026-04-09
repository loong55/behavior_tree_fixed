#include "behaviortree_cpp/bt_factory.h"
#include "std_msgs/msg/u_int8.hpp"
#include "rm_behavior_tree/plugins/condition/check_detect_enemy.hpp"
#include "geometry_msgs/msg/vector3.hpp"

namespace rm_behavior_tree
{
    IsDetectEnemycondition::IsDetectEnemycondition(const std::string & name, const BT::NodeConfig & config
    ): BT::SimpleConditionNode(name, std::bind(&IsDetectEnemycondition::checkDetectEnemy, this), config)
    {
    }
    BT::NodeStatus IsDetectEnemycondition::checkDetectEnemy()
    {
        //int message;
        auto msg = getInput<geometry_msgs::msg::Vector3>("message");
        if (!msg)
        {
            return BT::NodeStatus::FAILURE;
        }
        //需要显示比较
        if (msg.value().z == static_cast<double>(1) || msg.value().z == static_cast<double>(2))
        {
            return BT::NodeStatus::SUCCESS;
        }
        else 
        {
            return BT::NodeStatus::FAILURE;
        }
    }
}   //namespace rm_behavior_tree


BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<rm_behavior_tree::IsDetectEnemycondition>("IsDetectEnemy");
}