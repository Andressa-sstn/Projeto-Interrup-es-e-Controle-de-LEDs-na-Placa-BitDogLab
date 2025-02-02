# Projeto-Interrup-es-e-Controle-de-LEDs-na-Placa-BitDogLab

---

## 📌 **Passo a Passo para Desenvolvimento e Entrega do Projeto**

### **1️⃣ Configuração do Ambiente**
- **Micro C/C++ SDK** para programação do RP2040.
- **Thonny IDE  **VS Code com extensão do Pico-SDK** (para C++).
- **Biblioteca neopixel **Adafruit Neopixel (C++)**.

---

### **2️⃣ Esquema de Conexões**
| Componente         | GPIO (RP2040) |
|--------------------|--------------|
| Matriz WS2812 (5x5) | 7 |
| LED RGB (R, G, B)  | 11, 12, 13 |
| Botão A           | 5 |
| Botão B           | 6 |

---

### **3️⃣ Desenvolvimento do Código**
O código deve incluir:
✅ **Interrupções (IRQ) para os botões**  
✅ **Debouncing via software**  
✅ **Piscar do LED RGB na frequência correta**  
✅ **Controle da matriz WS2812 para exibir números de 0 a 9**  

---

### **4️⃣ Estrutura do Código**
Crie um diretório no GitHub com a seguinte estrutura:

```
📂 BitDogLab_Project
 bitdoglab-interruptions/
│── src/
│   ├── main.c
│   ├── ws2812.pio.h
│   ├── ws2812.c
│── CMakeLists.txt
│── README.md
│── video.mp4

```

- **README.md** → Explicação do projeto e como rodá-lo.  
- **src/** → Código-fonte.  
- **docs/** → Imagens e explicação técnica.  
- **video/** → Vídeo da demonstração do projeto.

---

### **5️⃣ Subindo para o GitHub**
1. Crie um repositório no GitHub.
2. No terminal, rode:
   ```bash
   git init
   git add .
   git commit -m "Primeira versão do projeto"
   git branch -M main
   git remote add origin https://github.com/seu-usuario/BitDogLab_Project.git
   git push -u origin main
   ```
3. Confirme que todos os arquivos estão no repositório.

---

### **6️⃣ Criando o Vídeo de Demonstração**
- A
- Mostre o hardware funcionando.
- Exemplo de fala:
  
---

*7️⃣ Entrega Final**
✅ Código no GitHub ou arquivo   
✅ README explicativo  
✅ Vídeo demonstrativo  

-** Criadora do código 
Andressa Silva Santos 
