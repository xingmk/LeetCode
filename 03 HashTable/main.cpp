/*
242:	��Ч����ĸ��λ��
*/
{
	bool isAnagram(string s, string t) {
        int hash[26] = {0};
        // ͳ��s
        for (int i : s){
            hash[i - 'a']++;
        }
        // ͳ��t
        for (int j : t){
            hash[j - 'a']--;
        }
        // �ж�hash
        for (int k : hash){
            if (k != 0) return false;
        }
        return true;
    }
}
// ͬ��
{
    int record[26] = { 0 };
    for (int i = 0; i < s.size(); i++) {
        // ������Ҫ��ס�ַ�a��ASCII��ֻҪ���һ�������ֵ�Ϳ�����
        record[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            // record��������е�Ԫ�ز�Ϊ��0��˵���ַ���s��t һ����˭�����ַ�����˭�����ַ���
            return false;
        }
    }
    // record��������Ԫ�ض�Ϊ��0��˵���ַ���s��t����ĸ��λ��
    return true;
}

/*
349:    ��������Ľ���
*/
// ����
{
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // ��Ž����֮������set��Ϊ�˸������ȥ��
        int hash[1005] = {0}; // Ĭ����ֵΪ0
        for (int num : nums1) { // nums1�г��ֵ���ĸ��hash����������¼
            hash[num] = 1;
        }
        for (int num : nums2) { // nums2�г��ֻ���result��¼
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
}
// set
{
    vector<int> intersection(vector<int>&nums1, vector<int>&nums2) {
        unordered_set<int> result_set; // ��Ž����֮������set��Ϊ�˸������ȥ��
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
}
/*
1   ����֮��
*/
{
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // ������ǰԪ�أ�����map��Ѱ���Ƿ���ƥ���key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // ���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
}

/*
454:   �������||
*/
{
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap; //key:a+b����ֵ��value:a+b��ֵ���ֵĴ���
        // ������A�ʹ�B���飬ͳ����������Ԫ��֮�ͣ��ͳ��ֵĴ������ŵ�map��
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        int count = 0; // ͳ��a+b+c+d = 0 ���ֵĴ���
        // �ڱ�����C�ʹ�D���飬�ҵ���� 0-(c+d) ��map�г��ֹ��Ļ����Ͱ�map��key��Ӧ��valueҲ���ǳ��ִ���ͳ�Ƴ�����
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
}

/*
15:     ����֮��
*/
// ˫ָ��
{
    vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
            if (nums[i] > 0) {
                return result;
            }
            // ����ȥ��a����������©��-1,-1,2 �������
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // ��ȷȥ��a����
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b �� cȥ��
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // �ҵ���ʱ��˫ָ��ͬʱ����
                    right--;
                    left++;
                }
            }

        }
        return result;
}
// Hash
{
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô�����ܴճ���Ԫ��
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //��Ԫ��Ԫ��aȥ��
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // ��Ԫ��Ԫ��bȥ��
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// ��Ԫ��Ԫ��cȥ��
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
}/*
 18     ����֮�� 
 */
// ˫ָ��
{
    vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // ��֦����
            if (nums[k] > target && nums[k] >= 0) {
            	break; // ����ʹ��break��ͳһͨ������return����
            }
            // ��nums[k]ȥ��
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2����֦����
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // ��nums[i]ȥ��
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target �����
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target �����
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // ��nums[left]��nums[right]ȥ��
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // �ҵ���ʱ��˫ָ��ͬʱ����
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
}