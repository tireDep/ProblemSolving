#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	vector<int> tempVector;

	for (int k = 0; k < commands.size(); k++)
	{
		// get
		for (int i = 0; i < array.size(); i++)
		{
			if (commands[k][0] - 1 <= i && commands[k][1] - 1 >= i)
				tempVector.push_back(array[i]);
		}

		// sort
		for (int i = 0; i<tempVector.size(); i++)
		{
			for (int j = i + 1; j<tempVector.size(); j++)
			{
				if (tempVector[i] >= tempVector[j])
				{
					int temp = tempVector[i];
					tempVector[i] = tempVector[j];
					tempVector[j] = temp;
				}
			}
		}

		answer.push_back(tempVector[commands[k][2] - 1]);
		tempVector.clear();
	}

	return answer;
}