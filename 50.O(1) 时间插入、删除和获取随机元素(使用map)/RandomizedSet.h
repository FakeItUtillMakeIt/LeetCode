#pragma once
#ifndef RANDOMIZED_SET_H
#define RANDOMIZED_SET_H

#include <unordered_map>
#include <map>
#include <random>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    //��ϣ��key���ֵ��value����±�
    unordered_map<int, int>numToLocation;
    //����
    vector<int>nums;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //����ڹ�ϣ���д��ڸ�Ԫ�أ�����false
        if (numToLocation.find(val) != numToLocation.end())
        {
            return false;
        }
        //��ϣ���м���ֵ�Ͷ�Ӧ�±꣬��Ϊ�����в����������һ���±����һ���±꣬���Զ�Ӧ���±�Ϊnums.size()
        numToLocation[val] = nums.size();
        //����ĩβ��val
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //�����ϣ���в����ڸ�Ԫ�أ��򷵻�false
        if (numToLocation.find(val) == numToLocation.end())
        {
            return false;
        }
        //�ڹ�ϣ���и��ݴ�ɾ��Ԫ���ҵ���ɾ��Ԫ���������е��±�
        int location = numToLocation[val];
        //�����������һ��Ԫ�ص��±��Ϊlocation
        numToLocation[nums.back()] = location;
        //�ڹ�ϣ����ɾ��val
        numToLocation.erase(val);
        //�������д�ɾ��Ԫ�������������һ��Ԫ���滻
        nums[location] = nums.back();
        //ɾ�����һ��Ԫ��
        nums.pop_back();
        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};



 

#endif