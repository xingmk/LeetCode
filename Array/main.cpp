/*
	���ֲ���
		>= X
	> 	= (>= X) + 1
	<   = (>= X) -1
	<=  = (>= X + 1) -1
*/
{
	// ������
	int lo = 0, hi = arr.size() - 1;

	while (lo <= hi) {		// С�ڵ���  hi<lo ʱ���� 
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

	// ����ҿ� 
	int lo = 0, hi = arr.size() - 1;

	while (lo < hi) {		// С�� ���ʱ���� 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target) {
			lo = mid + 1;
		}
		else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi; 			// lo hi ���Ǵ� 
	return lo;

	// ȫ�� 
	int lo = -1, hi = arr.size();

	while (lo + 1 < hi) {		// lo hi ����ʱ���� 
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
	���ֲ���
leetcode: 704
*/
{
	// ������
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

	// ����ҿ� 
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
	���� && ˫ָ��
leetcode: 27
*/
{
// ����
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

// ˫ָ��
	int slow = 0;
	for (int fast = 0; fast < nums.size(); fast++) {
		nums[slow] = nums[fast];
		slow++;
	}
	return slow;
}


