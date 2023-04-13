/*
	二分查找
		>= X
	> 	= (>= X) + 1
	<   = (>= X) -1
	<=  = (>= X + 1) -1
*/
{
	// 闭区间
	int lo = 0, hi = arr.size() - 1;

	while (lo <= hi) {		// 小于等于  hi<lo 时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target) {
			lo = mid + 1;
		}
		else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi-1; 
	return lo;

	// 左闭右开 
	int lo = 0, hi = arr.size() - 1;

	while (lo < hi) {		// 小于 相等时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target) {
			lo = mid + 1;
		}
		else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi; 			// lo hi 都是答案 
	return lo;

	// 全开 
	int lo = -1, hi = arr.size();

	while (lo + 1 < hi) {		// lo hi 相邻时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target) {
			lo = mid;
		}
		else {
			// arr[mid] >= target
			hi = mid;
		}
	}
	return hi;

}

/*
	二分查找
leetcode: 704
*/
{
	// 闭区间
	int lo = 0, hi = nums.size() - 1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] < target) {
			lo = mid + 1;
		}
		else if (nums[mid] > target {
			hi = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;

	// 左闭右开 
	int lo = 0, hi = arr.size() - 1;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] < target) {
			lo = mid + 1;
		}
		else if (nums[mid] > target) {
			hi = mid;
		}
		else {
			return mid;
		}
	}
	return -1;
}

/*
	暴力 && 双指针
leetcode: 27
*/
{
// 暴力
	int size = nums.size();
	for (int i=0; i<size; i++){
		if (nums[i] == val){
		for (int j=i+1; j<size; j++){
			nums[j-1] = nums[j];
		}
		i--;
		size--;
	}
}
	return size;

// 双指针
	int slow = 0;
	for (int fast = 0; fast < nums.size(); fast++) {
		nums[slow] = nums[fast];
		slow++;
	}
	return slow;
}


