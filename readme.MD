# 🎓 Student Performance Analyzer (C Project)

The *Student Performance Analyzer* is a C-based application designed to evaluate, analyze, and predict student academic performance using subject-wise marks.  
It calculates averages, assigns grades, categorizes performance levels, predicts future scores, and identifies weak subjects with suggestions for improvement.

---

## Features

###  Marks Input  
- Accepts marks for *5 subjects* per student  
- Supports multiple students at a time  

###  Analytics  
- Calculates *average marks*  
- Assigns *grades* (A, B, C, D, F)  
- Categorizes performance as:  
  - Excellent  
  - Good  
  - Average  
  - Critical  
###  Weakness Detection  
Identifies subject-wise weak areas:
- Fail (<40) → Needs urgent improvement  
- Weak (40–59) → Practice more tests  
- Can Improve (60–74) → Increase revision  
- Strong (75+)  

###  Score Prediction  
Predicts the next expected score using a weighted formula:
- Subject3 → 20%  
- Subject4 → 30%  
- Subject5 → 50%  

###  Report Generation  
Creates a file: