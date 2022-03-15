# 其他

## 力扣常见问题

### 1.stack-buffer-overflow

遇到该错误时，可能由于代码的逻辑出现错误，比如循环（递归）的结束条件错误导致循环无法跳出！

解决方法：检查程序中每一处跳出循环（递归）的条件是否正确。

### 2.heap-buffer-overflow

这种错误的产生原因一般是数组越界，可能初始化的数组不够长或者在程序中出现了下标越界的情况。

解决方法：检查代码中数组下标是否使用正确，排除越界的可能性。
