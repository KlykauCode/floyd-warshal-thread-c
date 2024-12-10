# Cíl semestrální práce

Cílem semestrální práce je implementace algoritmu **Floyd-Warshall** pro hledání nejkratších cest mezi všemi dvojicemi vrcholů v grafu v programovacím jazyce **C++**.

Práce zahrnuje:
- Vytvoření **jednovláknové** a **vícevláknové** verze tohoto algoritmu.
- **Srovnání obou implementací** z hlediska výkonnosti.
- Možnost přepínat mezi implementacemi pomocí přepínače na příkazové řádce.

**Požadavky:**
- Implementace využívající více vláken musí dosahovat **vyšší rychlosti** než jednovláknová verze.
- Program musí projít kontrolou nástroji jako **Valgrind** a **Helgrind**, což zajišťuje správnou správu paměti a absenci závodních podmínek.
- Program musí být **přenositelný napříč různými architekturami a operačními systémy**, bez použití rozšíření jazyka podporovaných pouze některými kompilátory, nebo přímo rozhraní **WINAPI** a **POSIX**, s výjimkou knihovny **pthread**.

### Funkce programu:
- Program poskytuje **neinteraktivní rozhraní**, které přijímá vstupy:
    - Z příkazové řádky.
    - Ze souboru.
    - Ze standardního vstupu.

- Implementace přepínače **--help**, který vypíše návod k použití a ukončí program.
- Program **neakceptuje neznámé přepínače**, a v případě neznámého přepínače vypíše chybovou zprávu.

### Srovnání implementací:
- Výsledky srovnání obou implementací jsou znázorněny v **grafu**, který ukazuje rozdíly ve výkonu při různých velikostech vstupních dat. Tento graf umožňuje **vizuální porovnání efektivity** jednovláknové a vícevláknové verze algoritmu **Floyd-Warshall**.

---

## Shrnutí klíčových bodů:

- **Implementace algoritmu Floyd-Warshall** v **C++** ve dvou variantách: **jednovláknové** a **vícevláknové**.
- **Srovnání výkonu** obou implementací pomocí přepínače na příkazové řádce.
- **Vícevláknová verze** musí být **rychlejší** než jednovláknová.
- **Kontrola kvality kódu** pomocí nástrojů **Valgrind** a **Helgrind**.
- **Přenostitelnost programu** napříč různými architekturami a operačními systémy.
- **Neinteraktivní uživatelské rozhraní** s podporou přepínače **--help** a chybovým hlášením pro neznámé přepínače.
- **Vizualizace výsledků** prostřednictvím grafu pro snadné porovnání výkonnosti.

---

## DŮLEŽITÁ INFORMACE:
**Pozor**: Aplikace zobrazuje data o cestách mezi každými dvěma vrcholy, původní matici a matici po provedení algoritmu **pouze pro grafy s méně než 20 vrcholy**, protože pro grafy s více než 20 vrcholy se matice a cesty mezi vrcholy stávají **nečitelnými**.

Grafy byly vygenerovány pomocí generátoru skriptu v **Pythonu**, který se nachází ve složce, kde jsou i všechny grafy. Pro spuštění aplikace je potřeba **přesunout soubor `graph1.txt`** do složky `c-make-build`!

---

## MĚŘENÍ:
**Měření jsem prováděl na procesoru AMD Ryzen 5 7535HS** s **Radeon Graphics** o frekvenci **3,30 GHz**, který má **6 jader a 12 vláken**. Používal jsem grafy s různým počtem vrcholů. Pro každý algoritmus jsem použil jeden graf a porovnával, jak dlouho trvá provedení jednovláknového a víceválkového algoritmu.

Níže je uveden **graf porovnání doby běhu**:

![Graf výkonu](measurement/performance_comparison.png)

**Graf byl vytvořen pomocí knihoven Matplotlib a Pandas.**

### Tabulka výsledků:

| Vertices | Single-thread (ms) | Multi-thread (ms) |
|----------|---------------------|-------------------|
| 10       | 0                   | 2                 |
| 20       | 0                   | 3                 |
| 30       | 0                   | 5                 |
| 40       | 1                   | 8                 |
| 50       | 1                   | 9                 |
| 100      | 14                  | 21                |
| 200      | 114                 | 54                |
| 300      | 385                 | 122               |
| 400      | 905                 | 247               |
| 500      | 1796                | 507               |
| 600      | 3020                | 735               |
| 700      | 4766                | 1112              |
| 800      | 7164                | 2657              |
| 900      | 10203               | 2958              |
| 1000     | 14334               | 3159              |
| 2000     | 113828              | 29919             |

