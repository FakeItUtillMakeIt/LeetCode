class Solution {
public:
    string defangIPaddr(string address) {
		string out;
		for (char ch:address)
		{
			if (ch=='.')
			{
				out.append("[.]");
				continue;
			}
			out.push_back(ch);
			
		}
		return out;
	}
};