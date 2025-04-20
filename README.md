# 🏫 Managing Dormitories Digitally (C++ Project)

This project was developed as a final assignment for my first semester (Fall 2023). It is a C++-based system designed to digitally manage the daily operations of a college dormitory, focusing on resident move-ins/outs and visitor check-ins/outs, while enforcing campus housing rules.

---

## 🚀 Features

- Digitally tracks resident **move-in** and **move-out**.
- Allows **visitor check-in** and **check-out** with built-in rule enforcement.
- Enforces gender-based visitor restrictions and time-based entry policies.
- Validates input formats for:
  - Student IDs (must be numeric)
  - Names (case-insensitive handling)
  - Room numbers (within valid range)

---

## 🏢 Assumptions & Rules Modeled

- The dormitory has **20 rooms**, with **1 resident per room**.
- **Visitors must be students** from the same campus.
- **Only one visitor per room** is allowed at a time.
- **Gender-restricted visitation**: Opposite-gender visitors are not permitted.
- **Visiting hours**: 
  - Check-ins allowed only between **6:00 a.m. and 12:00 a.m. (midnight)**.
  - Visitors must check out **before midnight**, or it's considered a violation.
- **Each student (resident or visitor)** must have a **unique Student ID**.

---

## ⚙️ Technical Highlights

- Developed in **C++** with a focus on **object-oriented design**.
- Handles **invalid input gracefully**, such as:
  - Alphabetic or alphanumeric Student IDs
  - Invalid room numbers (e.g., outside 1–20 range)
  - Mixed-case or improperly formatted names

---

## ⭐ Star This Repo

If you found this useful, please consider starring the repo to support the project!
