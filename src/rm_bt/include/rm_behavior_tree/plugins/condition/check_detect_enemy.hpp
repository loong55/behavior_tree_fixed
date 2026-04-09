#ifndef RM_BEHAVIOR_TREE__PLUGINS__CONDITION__CHECK_DETECT_ENEMY_HPP_
#define RM_BEHAVIOR_TREE__PLUGINS__CONDITION__CHECK_DETECT_ENEMY_HPP_

#include "behaviortree_cpp/condition_node.h"
#include "geometry_msgs/msg/vector3.hpp"  

namespace rm_behavior_tree
{
    /**
     * @brief condition节点，用于判断比赛是否检测到敌人
     * @param[in] message.z 比赛状态 {0, 未检测到敌人} {1 or 2, 检测到敌人}
     */
    class IsDetectEnemycondition : public BT::SimpleConditionNode
    {
        public:
            IsDetectEnemycondition(const std::string & name, const BT::NodeConfig & config);

            BT::NodeStatus checkDetectEnemy();

            static BT::PortsList providedPorts()
            {
                return{
                    BT::InputPort<geometry_msgs::msg::Vector3>("message")
                };
            }
    };
}   // namespace rm_behavior_tree

#endif //RM_BEHAVIOR_TREE__PLUGINS__CONDITION__CHECK_DETECT_ENEMY_HPP_