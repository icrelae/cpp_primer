/* 2016.11.14 20:45
 * P_294
 * !!!
 * difference of sequential containers: !!!
 * string, vector: 连续存储，随机访问快速，中间位置增删慢，一次插入/删除后续全
 * 部元素都要移动，添加可能需要分配额外空间，进而导致全部元素都要移至新的存储空
 * 间中。
 * list, forward_list: 任意位置增删都很快，不支持随机访问，额外内存开销大
 * deque: 双端队列，支持快速随机访问，中间位置增删慢，两端增删快。
 *
 * a) list
 * b) deque
 * c) vector
 */
