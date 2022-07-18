/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/16
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Program Assignment 3

Description: This program will read student data from a file, calculate the mean, and 
             deviations of certain subesets of this data then print to an output file.
*******************************************************************************************/

#include "Calculations.h"

int main(void)
{
    // Variable Declarations

    FILE *infile = NULL;
    FILE *outfile = NULL;

    infile = fopen("input.dat", "r");
    outfile = fopen("output.dat", "w");

    int studentOneId = 0, studentTwoId = 0, 
        studentThreeId = 0, studentFourId = 0, studentFiveId = 0;
    
    double studentOneGpa = 0.0, studentTwoGpa = 0.0, 
        studentThreeGpa = 0.0, studentFourGpa = 0.0, studentFiveGpa = 0.0;
    
    int studentOneClassStanding = 0, studentTwoClassStanding = 0, 
        studentThreeClassStanding = 0, studentFourClassStanding = 0, studentFiveClassStanding = 0;
    
    double studentOneAge = 0.0, studentTwoAge = 0.0,
        studentThreeAge = 0.0, studentFourAge = 0.0, studentFiveAge = 0.0;

    // 1. Reading all of the data in and assigning it to their respective variables.
    // I know that you don't have to assign the IDs (becuase the're not used), but I did it just because.
    studentOneId = read_int(infile);
    studentOneGpa = read_double(infile);
    studentOneClassStanding = read_int(infile);
    studentOneAge = read_double(infile);

    studentTwoId = read_int(infile);
    studentTwoGpa = read_double(infile);
    studentTwoClassStanding = read_int(infile);
    studentTwoAge = read_double(infile);

    studentThreeId = read_int(infile);
    studentThreeGpa = read_double(infile);
    studentThreeClassStanding = read_int(infile);
    studentThreeAge = read_double(infile);

    studentFourId = read_int(infile);
    studentFourGpa = read_double(infile);
    studentFourClassStanding = read_int(infile);
    studentFourAge = read_double(infile);

    studentFiveId = read_int(infile);
    studentFiveGpa = read_double(infile);
    studentFiveClassStanding = read_int(infile);
    studentFiveAge = read_double(infile);


    double sum_of_gpa = 0.0;
    // 2. Calculating sum of GPAs
    sum_of_gpa = calculate_sum(studentOneGpa, studentTwoGpa, studentThreeGpa, studentFourGpa, studentFiveGpa);

    double sum_of_ClassStandings = 0.0;
    // 3. Calculating Sum of Class Standings
    sum_of_ClassStandings = calculate_sum(studentOneClassStanding, studentTwoClassStanding, 
        studentThreeClassStanding, studentFourClassStanding, studentFiveClassStanding);

    double sum_of_ages = 0.0;
    // 4. Calculating Sum of Ages
    sum_of_ages = calculate_sum(studentOneAge, studentTwoAge, studentThreeAge, studentFourAge, studentFiveAge);

    double mean_of_gpa = 0.0;
    // 5. Calculating the mean of the GPA then printing to file
    mean_of_gpa = calculate_mean(sum_of_gpa, 5); // 5 because there are 5 samples in the set.
    fprintf(outfile, "Mean GPA: ");
    print_double(outfile, mean_of_gpa);

    double mean_of_ClassStandings = 0.0;
    // 6. Calculating the mean of the Class Standings then printing to file
    mean_of_ClassStandings = calculate_mean(sum_of_ClassStandings, 5);
    fprintf(outfile, "Mean class standing: ");
    print_double(outfile, mean_of_ClassStandings);

    double mean_of_ages = 0.0;
    // 7. Calculating the mean of the Ages then printing to file
    mean_of_ages = calculate_mean(sum_of_ages, 5);
    fprintf(outfile, "Mean age: ");
    print_double(outfile, mean_of_ages);

    double studentOneDeviation = 0.0, 
           studentTwoDeviation = 0.0, 
           studentThreeDeviation = 0.0, 
           studentFourDeviation = 0.0, 
           studentFiveDeviation = 0.0;
    // 8. Calculating each student's deviation to the mean
    studentOneDeviation = calculate_deviation(mean_of_gpa, studentOneGpa);
    studentTwoDeviation = calculate_deviation(mean_of_gpa, studentTwoGpa);
    studentThreeDeviation = calculate_deviation(mean_of_gpa, studentThreeGpa);
    studentFourDeviation = calculate_deviation(mean_of_gpa, studentFourGpa);
    studentFiveDeviation = calculate_deviation(mean_of_gpa, studentFiveGpa);

    double variance = 0.0;
    // 9. Calculating the Variance of the set of data
    variance = calculate_variance(studentOneDeviation, studentTwoDeviation, 
        studentThreeDeviation, studentFourDeviation, studentFiveDeviation, 5); // 5 because there are 5 points of data in our set

    double standard_deviation = 0.0;
    // 10. Calculating the standard deviation of the data set then printing to the file.
    standard_deviation = calulate_standard_deviation(variance);
    fprintf(outfile, "\nStandard Deviation from mean (GPA): ");
    print_double(outfile, standard_deviation);

    double min_gpa = 0.0;
    // 12. Finding lowest gpa of the bunch then printing it to file.
    min_gpa = find_min(studentOneGpa, studentTwoGpa, studentThreeGpa, studentFourGpa, studentFiveGpa);
    fprintf(outfile, "Lowest GPA: ");
    print_double(outfile, min_gpa);

    double max_gpa = 0.0;
    // 11. Finding highest gpa of the bunch then printing it to file.
    max_gpa = find_max(studentOneGpa, studentTwoGpa, studentThreeGpa, studentFourGpa, studentFiveGpa);
    fprintf(outfile, "Highest GPA: ");
    print_double(outfile, max_gpa);
    
    // 12. Closing both of the files
    fclose(infile);
    fclose(outfile);

    // Just letting user know that the
    printf("Calculations are complete, files are closed and program is exiting...\nPress any key to continue, and have a good one!\n\n");

}