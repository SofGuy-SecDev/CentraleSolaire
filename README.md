# 🌞 Centrale Solaire Intelligente - Solar Tracker ESP32

**Projet** : Système de suivi solaire automatique pour optimiser la production d'énergie photovoltaïque, intégré à Home Assistant.

## 📌 Fonctionnalités
- **Suivi solaire 2 axes** (azimut/élévation) basé sur des calculs astronomiques.
- **Contrôle manuel** via interface web (vitesse, calibration).
- **Synchronisation matinale** automatique de l'azimut.
- **Intégration domotique** avec Home Assistant et OpenDTU.
- **Sécurité** : Capteurs de fin de course optique.

## 🛠 Matériel
- **Carte** : ESP32 (Wemos D1 Mini ESP32)
- **Moteurs** : Pas-à-pas 28BYJ-48 + Drivers ULN2003
- **Capteurs** : 
  - Fin de course (optique)
- **RTC** : DS3231 pour la gestion du temps
- **Connectivité** : Wi-Fi (ESP32 intégré)

## 📦 Bibliothèques
- `AccelStepper` (Contrôle des moteurs)
- `RTClib` (Gestion du temps)
- `WebServer` (Interface web)
- `PubSubClient` (MQTT pour Home Assistant)
