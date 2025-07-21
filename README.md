# Control Volum cu Potențiometru, LCD și LED-uri


## 📌 Enunțul proiectului

Un potențiometru controlează „volumul” (valoare între 0% și 100%). Valoarea este afișată pe un ecran LCD și este semnalizată proporțional prin aprinderea unor LED-uri. La atingerea valorii de 100%, se aprinde un LED special de "maxim".

---

## 📖 Descriere

Acest proiect are ca scop realizarea unui sistem interactiv de afișare și semnalizare a unei valori procentuale de volum, controlată printr-un potențiometru.

🔧 Utilizatorul poate roti potențiometrul pentru a ajusta valoarea între 0% și 100%. Sistemul afișează această valoare în timp real pe un ecran LCD (cu interfață I2C), oferind o prezentare clară și intuitivă.

💡 În plus, cinci LED-uri semnalizează vizual volumul:

- 1 LED pentru 0-25%
- 2 LED-uri până la 50%
- 3 LED-uri până la 75%
- 4 LED-uri până la 99%
- Al 5-lea LED se aprinde doar la 100%, indicând atingerea nivelului maxim

Componente folosite:
- Arduino Uno
- Potențiometru
- LCD I2C 16x2
- 5 LED-uri
- Rezistențe și cabluri

---

## 💡 Scenariu de utilizare

Acest sistem este util oriunde este nevoie de o interfață vizuală simplă pentru afișarea unui nivel ajustabil:

🎛️ **Exemplu**: o boxă sau un mixer audio într-un mediu zgomotos. În loc să te bazezi pe ureche, utilizatorul vede imediat valoarea pe LCD și progresul prin LED-uri.

📈 Sistemul oferă:
- Afișaj numeric precis pe LCD
- Feedback vizual progresiv prin LED-uri
- Semnal clar când volumul este la maxim

Acest tip de interfață este ideal pentru aplicații precum:
- Reglaj volum audio
- Control luminozitate
- Control temperatură
- Control viteză motoare

---

## 🧩 Arhitectura sistemului

### Componente principale:

- **🔘 Potențiometru**  
  Intrare analogică, generează semnal între 0 și 5V proporțional cu poziția rotativă.

- **🧠 Arduino Uno**  
  - Citește valoarea analogică de la potențiometru
  - Calculează procentul (0-100%)
  - Trimite date către:
    - **LCD I2C** pentru afișaj
    - **LED-uri** pentru semnalizare treptată

- **📺 LCD I2C**  
  Afișează procentul exact al volumului (ex. `Volum: 75%`)

- **💡 LED-uri**  
  Aprinse progresiv la 25%, 50%, 75%, 100%, cu un LED special pentru maxim.

---


## 📦 Direcții de extindere

- Reglaj PWM pentru LED-uri (intensitate variabilă)
- Senzor de lumină ambientală pentru ajustare automată
- Buzzer la atingerea valorii maxime
- Interfață serială pentru monitorizare în PC

---

## ✅ Concluzie

Acest proiect combină electronică de bază cu un concept intuitiv de interfață om-mașină. Este ideal pentru începători și poate fi extins în multe direcții creative.

---

## 📁 Structura fișierelor

