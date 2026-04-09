# behavior_tree_fixed

- BehaviorTree.ROS2

行为树相关依赖，修改了bt_action_node.hpp基类，在halt()中解决了因为行为树条件发生改变时action 报的Goalhandle error错误，即调用whledoelse判断条件发生改变时行为树程序死亡问题。解决 思路为条件发生改变，调用halt()时直接强制对任务节点赋值Success。

- rm_bt

行为树核心，包括编写的各种行为树插件以及决策代码

- rm_sentry_decision_interfaces

行为树需要的自定义消息类型

