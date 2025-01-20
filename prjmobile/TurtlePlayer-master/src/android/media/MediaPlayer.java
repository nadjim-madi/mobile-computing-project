package android.media;

import android.util.Log;

public class MediaPlayer {

    // État actuel du MediaPlayer (par exemple, en lecture, en pause)
    private int state;

    // Constructeur de la classe MediaPlayer
    public MediaPlayer() {
        state = 0; // Initialement, l'état est "prêt"
    }

    // Méthode pour définir la source du média (fichier audio/vidéo)
    public void setDataSource(String path) throws Exception {
        // Code pour charger le fichier à partir du chemin spécifié
        Log.d("MediaPlayer", "Source du média définie : " + path);
    }

    // Méthode pour préparer le MediaPlayer avant de démarrer
    public void prepare() throws Exception {
        // Code pour préparer le média
        Log.d("MediaPlayer", "Média préparé.");
    }

    // Méthode pour démarrer la lecture du média
    public void start() {
        // Code pour démarrer la lecture
        state = 1; // L'état passe à "lecture"
        Log.d("MediaPlayer", "Lecture démarrée.");
    }

    // Méthode pour mettre en pause la lecture
    public void pause() {
        // Code pour mettre en pause
        state = 2; // L'état passe à "pause"
        Log.d("MediaPlayer", "Lecture en pause.");
    }

    // Méthode pour libérer les ressources utilisées par le MediaPlayer
    public void release() {
        // Code pour libérer les ressources
        state = 0; // Retour à l'état initial
        Log.d("MediaPlayer", "Ressources libérées.");
    }

    // Interface interne pour écouter la fin de la lecture
    public interface OnCompletionListener {
        void onCompletion(MediaPlayer mp);
    }

    // Méthode pour définir un OnCompletionListener
    public void setOnCompletionListener(OnCompletionListener listener) {
        // Code pour associer un écouteur
        Log.d("MediaPlayer", "OnCompletionListener défini.");
    }
}
