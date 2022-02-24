/* 
Given a circular linked list, return the node at the beginning of the loop
解题分析:寻找某个特定位置，
用runner technique。Runner以两倍速度遍历，假定有loop，那么runner与chaser一定能在某点相遇。
相遇后，再让chaser从head出发再次追赶runner，第二次相遇的节点为loop开始的位置。
*/