# 💡 Lights Out Solver over Z₂ (GF(2))

Tento projekt implementuje **řešič hry Lights Out** pomocí **Gaussovy eliminace v tělese Z₂ (mod 2)**.  
Každé políčko světelného pole je reprezentováno jedním bitem (0 = zhasnuto, 1 = svítí), a stisk tlačítka ovlivní aktuální i sousední světla.

---

## 📘 Popis

Program vytvoří matici A (rozměru n² × n²), kde každý sloupec představuje účinek stisku jednoho tlačítka.  
Výsledný systém lineárních rovnic `A * x = b (mod 2)` se řeší pomocí **Gaussovy eliminace** nad tělesem GF(2).

- `A` — matice vlivu tlačítek  
- `b` — počáteční stav světel  
- `x` — řešení: které tlačítka je potřeba stisknout

---

## ⚙️ Funkcionalita

- Implementace třídy **Z2** pro aritmetiku modulo 2 (součet, rozdíl, násobení, dělení, porovnání)
- Generování matice **A** na základě rozměru `n`
- Řešení soustavy lineárních rovnic **Gaussovou eliminací nad GF(2)**
- Výpis výsledného řešení (0 = nestisknout, 1 = stisknout)

---

## ▶️ Použití

### Kompilace
```bash
g++ main.cpp -o lightsout
```

### Spuštění
```bash
./lightsout n b₁ b₂ b₃ ... bₙ²
```

- `n` je velikost pole (např. 3 → 3×3)
- `b₁ ... bₙ²` je počáteční stav světel (0 nebo 1)

### Příklad

Pro 3×3 pole se stavem:
```
1 0 0
0 1 0
0 0 1
```
spustíš:
```bash
./lightsout 3 1 0 0 0 1 0 0 0 1
```

Výstup (např.):
```
010 110 001
```
→ určuje, která tlačítka je třeba stisknout.

---

## 🧠 Poznámky

- Operace probíhají **v tělese GF(2)**, tj. všechna čísla se počítají mod 2.  
- V kódu je pro přehlednost definována pomocná třída `Z2`, která přetěžuje základní aritmetické operátory.

---
