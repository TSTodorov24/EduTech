<div align="center">

<img src="Media/logo/logo.png" alt="EduTech Logo" width="500">

<br>

# ⚡ EduTech — Electronic School ⚡


<br>

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Console-black?style=for-the-badge&logo=windows-terminal&logoColor=white)
![Questions](https://img.shields.io/badge/Questions-120-brightgreen?style=for-the-badge)
![Grade](https://img.shields.io/badge/Grading-Bulgarian%206--Point%20Scale-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

<br>

> **A full-featured C++ Electronic School built from scratch.**
> Quiz your students, track their progress, and make learning actually interesting.

<br>

---

</div>

## 🗂️ Table of Contents

- [What is EduTech?](#-what-is-edutech)
- [Features](#-features)
- [How It Works](#-how-it-works)
- [Question Bank](#-question-bank)
- [Grading System](#-grading-system)
- [Technologies](#️-technologies)
- [Getting Started](#-getting-started)
- [Team](#-team)
- [Milestones](#-milestones)

---

## 🎓 What is EduTech?

**EduTech** is a console-based C++ application that acts as a fully interactive **Electronic School Quiz System**. Students can test their knowledge, study structured material, and explore verified fun facts — all from the terminal.

Built entirely in **C++17** with zero external dependencies, EduTech covers three school subjects across **6 categories**, generates **34.1 billion unique test combinations**, and grades students on the **official Bulgarian 6-point scale**.

---

## ✨ Features

| Feature | Details |
|--------|---------|
| 📚 **Question Bank** | 120 questions — 40 per subject, 20 per category |
| 🎲 **Smart Test Generator** | 20 unique questions per test, zero repeats, randomly shuffled |
| ⚖️ **Weighted Scoring** | Basic categories = 1 pt, Advanced categories = 2 pts |
| 🏆 **Bulgarian Grading** | Official 6-point scale (Fail → Excellent) |
| 📊 **Full Statistics** | Best/worst/average results + per-category success rates |
| 📖 **Study Material** | Structured, in-depth learning content for all 3 subjects |
| 💡 **Fun Facts** | 10 verified, non-repeating facts per subject |
| 🛡️ **Input Validation** | The app never crashes — every input is checked |
| 🔀 **Mixed Mode** | Take a test spanning all 6 categories at once |

---

## 🎮 How It Works

```
┌─────────────────────────────────────────────────────┐
│                    MAIN MENU                        │
│                                                     │
│   1. Start Test        → Choose subject, answer 20  │
│   2. View Statistics   → Full results & breakdown   │
│   3. Study Material    → Learn before you test      │
│   4. Fun Facts         → 10 facts, no repeats       │
│   5. Exit                                           │
└─────────────────────────────────────────────────────┘
```

**Test flow:**

```
Pick subject → 20 questions generated → Answer each →
Running score shown live → Final grade + category breakdown
```

Every question displays its **category** and **point value** before you answer.
After the test you receive your **score**, **percentage**, **grade**, and a **per-category breakdown**.

---

## 📚 Question Bank

```
Mathematics  ──┬── Arithmetic   (20 questions · 1 pt each)
               └── Algebra      (20 questions · 2 pts each)

Chemistry    ──┬── Elements     (20 questions · 1 pt each)
               └── Reactions    (20 questions · 2 pts each)

English      ──┬── Grammar      (20 questions · 1 pt each)
               └── Vocabulary   (20 questions · 2 pts each)
```

**How many unique tests are possible?**

> C(20,10) × C(20,10) = 184,756 × 184,756 ≈ **34.1 billion unique question combinations**

After selection, questions are additionally shuffled — making the number of truly distinct test experiences **astronomically large**.

---

## 🏅 Grading System

| Percentage | Grade | Label |
|-----------|-------|-------|
| 90% and above | **6** | ✅ Excellent |
| 75% – 89% | **5** | 🟢 Very Good |
| 60% – 74% | **4** | 🔵 Good |
| 45% – 59% | **3** | 🟡 Average |
| Below 45% | **2** | 🔴 Fail |

---

## 🛠️ Technologies

<div align="center">

### 💻 Language
<img src="Media/Used/c++.png" width="90" title="C++">

### 🧰 Tools
<img src="Media/Used/visual-studio.png" width="130" title="Visual Studio">
&nbsp;&nbsp;
<img src="Media/Used/GitHubLogo.png" width="75" title="GitHub">

### 🎨 Design
<img src="Media/Used/CanvaLogo.png" width="75" title="Canva">
&nbsp;&nbsp;
<img src="Media/Used/photoshop.logo.png" width="75" title="Photoshop">

### 📑 Docs & Presentation
<img src="Media/Used/WordLogo.png" width="75" title="Word">
&nbsp;&nbsp;
<img src="Media/Used/PowerPointLogo.png" width="75" title="PowerPoint">

### 💬 Communication
<img src="Media/Used/TeamsLogo.png" width="75" title="Teams">

</div>

---

## 🚀 Getting Started

**Clone the repository:**

```bash
git clone https://github.com/TSTodorov24/EduTech
cd EduTech
```

**Compile:**

```bash
g++ -std=c++17 -Wall -o EduTech main.cpp
```

**Run:**

```bash
./EduTech
```

> Requires a C++17-compatible compiler (GCC 7+, Clang 5+, MSVC 2017+).

---

## 📂 Documentation & Presentation

| 📋 Documentation | 🎤 Presentation |
|-----------------|----------------|
| [View Documentation](https://codingburgas-my.sharepoint.com/:w:/g/personal/tstodorov24_codingburgas_bg/IQBkdY8O7HC7TpXBDbkl6esSAYdG-85Ta2p9kVBaSM1HAuI?e=aPLZK2) | [View Presentation](https://codingburgas-my.sharepoint.com/:p:/g/personal/tstodorov24_codingburgas_bg/IQAaA9psHTcDT5yyiVcjpGTSAb2LAbYB_kqQdPgybtoEmRs?e=2PFPh6) |

---

## 👥 Team

<div align="center">

| | Name | Class | Role |
|--|------|-------|------|
| <img src="Media/Team/Teodor.png" width="120"> | [**Teodor Spasov Todorov**](https://github.com/TSTodorov24) | 9A | 🧭 Scrum Trainer |
| <img src="Media/Team/Rado.jpg" width="120"> | [**Radostin Veselinov Dimkirichev**](https://github.com/RVDimkirichev24) | 9A | ⚙️ Backend Developer |
| <img src="Media/Team/Oleksandra.jpg" width="120"> | [**Oleksandra Oleksandrivna Kikavska**](https://github.com/OOKikavsyka24) | 9A | 🔍 Quality Engineer |
| <img src="Media/Team/Kasabov.JPG" width="120"> | [**Alexander Antonov Kasabov**](https://github.com/AAKasabov24) | 9G | ⚙️ Backend Developer |

</div>

---

## 📈 Milestones

```
✅ Phase 1 — Planning the project idea and structure
✅ Phase 2 — Designing data structures (Question, StudentResult, Category)
✅ Phase 3 — Building the question bank (120 questions across 6 categories)
✅ Phase 4 — Implementing the test engine with unique, non-repeating selection
✅ Phase 5 — Grading system, statistics module, and category breakdown
✅ Phase 6 — Study Material and Fun Facts modules
✅ Phase 7 — Testing, bug fixing, and zero-warning cleanup
✅ Phase 8 — Documentation, presentation, and GitHub repository
```

---

<div align="center">

Made with ❤️ by **Team EduTech**

</div>