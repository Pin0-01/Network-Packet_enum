# Network Packet Processing System (C++ Enums & Type Safety)

Questo progetto implementa un sistema di elaborazione di pacchetti di rete, simulando il modo in cui un router o un firewall analizza il traffico. L'obiettivo principale è dimostrare l'uso avanzato delle **Enumerazioni (Enum)** e delle **Enum Class** per garantire un codice robusto, leggibile e privo di errori logici.

## Obbiettivi

- Implementare una gestione rigorosa dei tipi tramite `enum` e `enum class`.

- Utilizzare istruzioni `switch` per la mappatura dei dati e la validazione.

- Gestire il ciclo di vita di un pacchetto (Stato, Protocollo, Tipo).

- Applicare la logica di validazione basata su regole di rete reali (es. TCP vs UDP).

---

## Architettura del Sistema

Il sistema si basa su tre scenari definiti tramite enumerazioni:

### 1. Gestione dei Tipi e Protocolli

Per garantire la massima sicurezza, sono stati utilizzati diversi tipi di enumerazione:

- **`PacketType` (Enum)**: Definisce la natura del pacchetto (`DATA`, `CONTROL`, `ERROR`, `UNKNOWN`).

- **`Protocol` (Enum Class)**: Gestisce i protocolli di rete supportati (`TCP`, `UDP`, `HTTP`, `FTP`). L'uso della `enum class` previene conflitti tra nomi di protocolli simili in altri moduli.

- **`Status` (Enum Class)**: Traccia lo stato del pacchetto nel sistema (`PENDING`, `VALID`, `INVALID`, `TIMEOUT`).

### 2. La Classe `Packet`

Ogni oggetto `Packet` incapsula:

- Il tipo di dato trasportato.

- Il protocollo utilizzato.

- Lo stato di validazione corrente.

---

## Logica di Validazione (Validation Logic)

 Il sistema applica regole specifiche per determinare se un pacchetto è legittimo:

- **Pacchetti DATA**: Sono considerati `VALID` solo se utilizzano protocolli di trasporto come `TCP` o `UDP`.

- **Pacchetti CONTROL**: Sono validi solo se utilizzano il protocollo `TCP` (garantendo la consegna dei comandi).

- **Pacchetti ERROR**: Sono sempre accettati per permettere la diagnostica del sistema.

- **UNKNOWN**: Ogni pacchetto non identificato viene marcato automaticamente come `INVALID` per motivi di sicurezza.

---

## Struttura dei File

- `include/PacketType.hpp`: Definizione dell'enum per i tipi di pacchetto.

- `include/Protocol.hpp`: Definizione della enum class per i protocolli.

- `include/Status.hpp`: Definizione della enum class per gli stati.

- `include/Packet.hpp`: Interfaccia della classe Packet.

- `src/Packet.cpp`: Implementazione della logica di validazione e delle funzioni di utilità (conversione enum-to-string).

- `src/main.cpp`: Test set per la simulazione di vari scenari di traffico.
