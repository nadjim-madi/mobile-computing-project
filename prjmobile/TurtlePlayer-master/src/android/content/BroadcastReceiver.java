package android.content;

import android.os.Bundle;
import android.os.IBinder;

/**
 * Base class for code that receives and handles broadcast intents sent by `sendBroadcast(Intent)`.
 */
public abstract class BroadcastReceiver {
    public BroadcastReceiver() {
    }

    /**
     * This method is called when the BroadcastReceiver is receiving an Intent broadcast.
     * @param context The Context in which the receiver is running.
     * @param intent The Intent being received.
     */
    public abstract void onReceive(Context context, Intent intent);

    /**
     * Provides a way for the broadcast receiver to go into a pending state.
     */
    public final PendingResult goAsync() {
        // Implementation to allow processing of broadcast in a background thread.
        return new PendingResult();
    }

    /**
     * Aborts the current broadcast (if it is ordered).
     */
    public final void abortBroadcast() {
        // Stops the propagation of the broadcast to other receivers.
    }

    /**
     * Checks whether this receiver is aborting the broadcast.
     */
    public final boolean isOrderedBroadcast() {
        return false; // Default implementation.
    }

    // Internal implementations and helper functions omitted for brevity.
}
