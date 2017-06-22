#include "../Computing/Combination.hpp"
#include "../Computing/DigitsOperations.hpp"

using namespace Computing;

int main()
{
    int _v[] = {1,2,3,4,5,6,7,8,9,10};
    ProbabilisticPyramid<int, 10> p(_v);

    for(long long idx = 0 ; idx < p.GetNbCombinations() ; ++idx)
    {
        ProbabilisticPyramid<int, 10>::ProbabilisticSolution solution = p.GetCombination(idx);

        int sum = solution.a[0] + solution.a[1] + solution.a[5];

        if(solution.a[1] + solution.a[2] + solution.a[6] == sum &&
           solution.a[2] + solution.a[3] + solution.a[7] == sum &&
           solution.a[3] + solution.a[4] + solution.a[8] == sum &&
           solution.a[4] + solution.a[0] + solution.a[9] == sum
           )
        {
            int nbDigits = 0;

            nbDigits += NbDigits(solution.a[0]) + NbDigits(solution.a[1]) + NbDigits(solution.a[5]);
            nbDigits += NbDigits(solution.a[1]) + NbDigits(solution.a[2]) + NbDigits(solution.a[6]);
            nbDigits += NbDigits(solution.a[2]) + NbDigits(solution.a[3]) + NbDigits(solution.a[7]);
            nbDigits += NbDigits(solution.a[3]) + NbDigits(solution.a[4]) + NbDigits(solution.a[8]);
            nbDigits += NbDigits(solution.a[4]) + NbDigits(solution.a[0]) + NbDigits(solution.a[9]);

            if(nbDigits == 16)
            {
                if(solution.a[5] < solution.a[6] && solution.a[5] < solution.a[7] && solution.a[5] < solution.a[8] && solution.a[5] < solution.a[9])
                {
                    cout <<
                    solution.a[5] << "," << solution.a[1] << "," << solution.a[0] << ";" <<
                    solution.a[9] << "," << solution.a[0] << "," << solution.a[4] << ";" <<
                    solution.a[8] << "," << solution.a[4] << "," << solution.a[3] << ";" <<
                    solution.a[7] << "," << solution.a[3] << "," << solution.a[2] << ";" <<
                    solution.a[6] << "," << solution.a[2] << "," << solution.a[1] << ";" <<
                    endl;
                }

                if(solution.a[6] < solution.a[5] && solution.a[6] < solution.a[7] && solution.a[6] < solution.a[8] && solution.a[6] < solution.a[9])
                {
                    cout <<
                    solution.a[6] << "," << solution.a[2] << "," << solution.a[1] << ";" <<
                    solution.a[5] << "," << solution.a[1] << "," << solution.a[0] << ";" <<
                    solution.a[9] << "," << solution.a[0] << "," << solution.a[4] << ";" <<
                    solution.a[8] << "," << solution.a[4] << "," << solution.a[3] << ";" <<
                    solution.a[7] << "," << solution.a[3] << "," << solution.a[2] << ";" <<
                    endl;
                }

                if(solution.a[7] < solution.a[5] && solution.a[7] < solution.a[6] && solution.a[7] < solution.a[8] && solution.a[7] < solution.a[9])
                {
                    cout <<
                    solution.a[7] << "," << solution.a[3] << "," << solution.a[2] << ";" <<
                    solution.a[6] << "," << solution.a[2] << "," << solution.a[1] << ";" <<
                    solution.a[5] << "," << solution.a[1] << "," << solution.a[0] << ";" <<
                    solution.a[9] << "," << solution.a[0] << "," << solution.a[4] << ";" <<
                    solution.a[8] << "," << solution.a[4] << "," << solution.a[3] << ";" <<
                    endl;
                }

                if(solution.a[8] < solution.a[5] && solution.a[8] < solution.a[6] && solution.a[8] < solution.a[7] && solution.a[8] < solution.a[9])
                {
                    cout <<
                    solution.a[8] << "," << solution.a[4] << "," << solution.a[3] << ";" <<
                    solution.a[7] << "," << solution.a[3] << "," << solution.a[2] << ";" <<
                    solution.a[6] << "," << solution.a[2] << "," << solution.a[1] << ";" <<
                    solution.a[5] << "," << solution.a[1] << "," << solution.a[0] << ";" <<
                    solution.a[9] << "," << solution.a[0] << "," << solution.a[4] << ";" <<
                    endl;
                }

                if(solution.a[9] < solution.a[5] && solution.a[9] < solution.a[6] && solution.a[9] < solution.a[7] && solution.a[9] < solution.a[8])
                {
                    cout <<
                    solution.a[9] << "," << solution.a[0] << "," << solution.a[4] << ";" <<
                    solution.a[8] << "," << solution.a[4] << "," << solution.a[3] << ";" <<
                    solution.a[7] << "," << solution.a[3] << "," << solution.a[2] << ";" <<
                    solution.a[6] << "," << solution.a[2] << "," << solution.a[1] << ";" <<
                    solution.a[5] << "," << solution.a[1] << "," << solution.a[0] << ";" <<
                    endl;
                }
            }
        }
    }

    return 0;
}
