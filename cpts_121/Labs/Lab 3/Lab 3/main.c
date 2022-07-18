//////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: Creating a program that will take
// in information from the user and return 
// their daily caloric needs.
//////////////////////////////////////////////////


#include "CalorieCalc.h"

int main(void)
{
    // Variable Declarations

    FILE* infile = NULL;
    FILE* outfile = NULL;

    // 1. Opening files
    infile = fopen("UserInput.txt", "r");
    outfile = fopen("CalorieOutput.txt", "w");
    
    // 2. Reading in data to variables
    
    double p1Weight = 0.0, p2Weight = 0.0,
        p3Weight = 0.0, p4Weight = 0.0, p5Weight = 0.0;

    double p1Height_Ft = 0.0, p2Height_Ft = 0.0,
        p3Height_Ft = 0.0, p4Height_Ft = 0.0, p5Height_Ft = 0.0;
    
    char p1Gender = '\0', p2Gender = '\0', p3Gender = '\0',
        p4Gender = '\0', p5Gender = '\0';

    // Between 0-4 (sedentary -> Low Activity -> Moderate Activity -> High Activity -> Extra Activity)
    int p1ExerciseLevel = 0, p2ExerciseLevel = 0,
        p3ExerciseLevel = 0, p4ExerciseLevel = 0, p5ExerciseLevel = 0;

    double p1Age = 0.0, p2Age = 0.0,
        p3Age = 0.0, p4Age = 0.0, p5Age = 0.0;

    // 1. Reading all of the data in and assigning it to their respective variables.
    p1Age = read_double(infile);
    p1Weight = read_double(infile);
    p1Height_Ft = read_double(infile);
    p1Gender = read_char(infile);
    p1ExerciseLevel = read_int(infile);

    p2Age = read_double(infile);
    p2Weight = read_double(infile);
    p2Height_Ft = read_double(infile);
    p2Gender = read_char(infile);
    p2ExerciseLevel = read_int(infile);

    p3Age = read_double(infile);
    p3Weight = read_double(infile);
    p3Height_Ft = read_double(infile);
    p3Gender = read_char(infile);
    p3ExerciseLevel = read_int(infile);

    p4Age = read_double(infile);
    p4Weight = read_double(infile);
    p4Height_Ft = read_double(infile);
    p4Gender = read_char(infile);
    p4ExerciseLevel = read_int(infile);

    p5Age = read_double(infile);
    p5Weight = read_double(infile);
    p5Height_Ft = read_double(infile);
    p5Gender = read_char(infile);
    p5ExerciseLevel = read_int(infile);

    double p1Bmr = 0.0, p2Bmr = 0.0, p3Bmr = 0.0, p4Bmr = 0.0, p5Bmr = 0.0;
    // 3. Calculating all users BMR
    p1Bmr = calculate_bmr(p1Weight, convert_height_to_inches(p1Height_Ft), p1Gender, p1Age);
    p2Bmr = calculate_bmr(p2Weight, convert_height_to_inches(p2Height_Ft), p2Gender, p2Age);
    p3Bmr = calculate_bmr(p3Weight, convert_height_to_inches(p3Height_Ft), p3Gender, p3Age);
    p4Bmr = calculate_bmr(p4Weight, convert_height_to_inches(p4Height_Ft), p4Gender, p4Age);
    p5Bmr = calculate_bmr(p5Weight, convert_height_to_inches(p5Height_Ft), p5Gender, p5Age);
    
    printf("p1BMR: %.2lf\np2BMR: %.2lf\np3BMR: %.2lf\np4BMR: %.2lf\np5BMR: %.2lf\n", p1Bmr, p2Bmr, p3Bmr, p4Bmr, p5Bmr); // for debugging

    double p1Cal = 0.0, p2Cal = 0.0, p3Cal = 0.0, p4Cal = 0.0, p5Cal = 0.0;
    // 4. Calculating Calories
    p1Cal = calculate_calories(p1Bmr, p1ExerciseLevel);
    p2Cal = calculate_calories(p2Bmr, p2ExerciseLevel);
    p3Cal = calculate_calories(p3Bmr, p3ExerciseLevel);
    p4Cal = calculate_calories(p4Bmr, p4ExerciseLevel);
    p5Cal = calculate_calories(p5Bmr, p5ExerciseLevel);

    printf("\np1Cal: %.2lf\np2Cal: %.2lf\np3Cal: %.2lf\np4Cal: %.2lf\np5Cal: %.2lf\n", p1Cal, p2Cal, p3Cal, p4Cal, p5Cal); // for debugging

    // 5. Printing Values to outfile
    fprintf(outfile, "Person 1 Recommended Daily Calorie Intake: ");
    file_print_double(outfile, p1Cal);
    fprintf(outfile, "\nPerson 2 Recommended Daily Calorie Intake: ");
    file_print_double(outfile, p2Cal);
    fprintf(outfile, "\nPerson 3 Recommended Daily Calorie Intake: ");
    file_print_double(outfile, p3Cal);
    fprintf(outfile, "\nPerson 4 Recommended Daily Calorie Intake: ");
    file_print_double(outfile, p4Cal);
    fprintf(outfile, "\nPerson 5 Recommended Daily Calorie Intake: ");
    file_print_double(outfile, p5Cal);


    // 6. Closing Files
    fclose(infile);
    fclose(outfile);
    
    printf("Files are closed, have a good one!\n");
    



}