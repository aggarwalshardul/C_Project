#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char name[50];
    float marks[5];
    float average;
    char grade;
    char performance[20];
    float predicted;
    char weak_points[200];
} Student;

char calculate_grade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

void performance_category(float avg, char *category) {
    if (avg >= 90) strcpy(category, "Excellent");
    else if (avg >= 75) strcpy(category, "Good");
    else if (avg >= 60) strcpy(category, "Average");
    else strcpy(category, "Critical");
}

float predict_score(float m1, float m2, float m3) {
    return (m1*0.2 + m2*0.3 + m3*0.5);
}

void find_weakness(Student *s) {
    strcpy(s->weak_points, "");

    for (int i = 0; i < 5; i++) {
        if (s->marks[i] < 40) {
            char temp[50];
            sprintf(temp, "Subject %d: FAIL (Needs urgent improvement)\n", i+1);
            strcat(s->weak_points, temp);
        }
        else if (s->marks[i] < 60) {
            char temp[70];
            sprintf(temp, "Subject %d: Weak (Practice more tests)\n", i+1);
            strcat(s->weak_points, temp);
        }
        else if (s->marks[i] < 75) {
            char temp[70];
            sprintf(temp, "Subject %d: Can improve (Increase revision)\n", i+1);
            strcat(s->weak_points, temp);
        }
    }

    if (strlen(s->weak_points) == 0) {
        strcpy(s->weak_points, "No major weaknesses. Keep up the good work!");
    }
}

int main() {
    int n;
    Student s[MAX];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i+1);
        scanf("%s", s[i].name);

        float sum = 0;
        printf("Enter marks of 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
            sum += s[i].marks[j];
        }

        s[i].average = sum / 5.0;
        s[i].grade = calculate_grade(s[i].average);
        performance_category(s[i].average, s[i].performance);
        s[i].predicted = predict_score(s[i].marks[2], s[i].marks[3], s[i].marks[4]);

        find_weakness(&s[i]);
    }

    FILE *file = fopen("performance_report.txt", "w");
    if (!file) {
        printf("Error creating file.");
        return 1;
    }

    fprintf(file, "STUDENT PERFORMANCE ANALYSIS REPORT\n\n");

    printf("\n--- Student Performance Summary ---\n");

    for (int i = 0; i < n; i++) {
        printf("\nName: %s", s[i].name);
        printf("\nAverage: %.2f", s[i].average);
        printf("\nGrade: %c", s[i].grade);
        printf("\nPerformance: %s", s[i].performance);
        printf("\nPredicted Next Score: %.2f\n", s[i].predicted);
        printf("Weak Points:\n%s\n", s[i].weak_points);

        fprintf(file,
            "\nName: %s\nAverage: %.2f\nGrade: %c\nPerformance: %s\nPredicted Score: %.2f\nWeak Points:\n%s\n",
            s[i].name, s[i].average, s[i].grade, s[i].performance, s[i].predicted, s[i].weak_points
        );
    }

    fclose(file);

    printf("\nReport saved to performance_report.txt\n");

    return 0;
}