import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import android.os.Bundle;
import android.view.WindowManager;
import android.widget.TextView;

import com.imagpay.MessageHandler;
import com.imagpay.SwipeEvent;
import com.imagpay.SwipeHandler;
import com.imagpay.SwipeListener;
import com.imagpay.utils.DeviceUtils;
import android.util.Log;
import android.widget.Toast;
import android.os.Handler;
import android.os.Looper;
import com.imagpay.Settings;

import org.apache.cordova.CordovaWebView;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.apache.cordova.CordovaInterface;
import android.util.Log;
import android.widget.Toast;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class CardReader extends CordovaPlugin {
	
	private SwipeHandler _handler;
    private Handler _ui;
    private Settings _settings;
	/**
	* Constructor.
	*/
	public CardReader() {
		
	}
	/**
	* Sets the context of the Command. This can then be used to do things like
	* get file paths associated with the Activity.
	*
	* @param cordova The context of the main Activity.
	* @param webView The CordovaWebView Cordova is running in.
	*/
	public void initialize(CordovaInterface cordova, CordovaWebView webView) {
		super.initialize(cordova, webView);
		//Log.v(TAG,"Init CoolPlugin");
	}
	
	public boolean execute(final String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
		final int duration = Toast.LENGTH_SHORT;
		// Shows a toast
		//Log.v(TAG,"CoolPlugin received:"+ action);
		cordova.getActivity().runOnUiThread(new Runnable() {
		
			public void run() {
				Log.d("myApp", "onCreate") ;
				final Context context = cordova.getActivity().getApplicationContext();

				_handler = new SwipeHandler(cordova.getActivity().getApplicationContext());
				_handler.setReadonly(true);
				_settings = new Settings(_handler);
				_ui = new Handler(Looper.myLooper());
				_handler.addSwipeListener(new SwipeListener() {
					@Override
					public void onReadData(SwipeEvent event) {
						Log.d("myApp", "onreaddata") ;
					}

					@Override
					public void onParseData(SwipeEvent event) {
						Log.d("myApp", "onparsedata1") ;

						String result = event.getValue();
						Log.d("myApp", result);
						// hex string message
						//sendMessage("Final(16)=>% " + result);

						String[] tmps = event.getValue().split(" ");
						StringBuffer sbf = new StringBuffer();
						for (String str : tmps) {
							sbf.append((char) Integer.parseInt(str, 16));
							sbf.append(" ");
						}
						// char message: b{card number}^{card holder}^{exp date}{other track1 data}?;{track2 data}
						// or            b{card number}&{card holder}&{exp date}{other track1 data}?;{track2 data}
						final String data = sbf.toString().replaceAll(" ", "");
						int idx = data.indexOf("^");
						// plain text of card data
						if (data.toUpperCase().startsWith("B") && idx > 0 && data.indexOf("?") > 0) {
							//sendMessage("Final(10)=>% " + data);
							_ui.post(new Runnable() {
								@Override
								public void run() {
									int idx = data.indexOf("^");
									String cardNo = data.substring(1, idx);
									String cardHolder = "";
									String expDate = "";
									int idx1 = data.indexOf("^", idx + 1);
									if (idx1 > 0 && idx1 < data.length() - 4) {
										cardHolder = data.substring(idx + 1, idx1);
										expDate = data.substring(idx1 + 1, idx1 + 1 + 4);
									}

									Log.d("myApp", cardNo);
									Log.d("myApp", cardHolder);
									Log.d("myApp", expDate);
									Toast someToast = Toast.makeText(context,"Read card succussfuly!", Toast.LENGTH_LONG);
									someToast.show();
									//callbackContext.success(cardNo + "@" + expDate + "@" + cardHolder);
									PluginResult progressResult = new PluginResult(PluginResult.Status.OK, cardNo + "/" + cardHolder + "/" + expDate);
									progressResult.setKeepCallback(true);
									callbackContext.sendPluginResult(progressResult);
								}
							});
						}
						// encryption data of card data
						else if (data.length() > 20 + 5 + 4) {
							_ui.post(new Runnable() {
								@Override
								public void run() {
									Log.d("myApp", "*****");
									String cardNo = data.substring(1, data.indexOf("="));
									String cardHolder = data.substring(data.indexOf("=")+5);
									String expDate =data.substring(data.indexOf("=")+1, data.indexOf("=")+5);

									Toast someToast = Toast.makeText(context,"Read card succussfuly!", Toast.LENGTH_LONG);
									someToast.show();
									PluginResult progressResult = new PluginResult(PluginResult.Status.OK,cardNo + "/" + cardHolder + "/" + expDate);
									progressResult.setKeepCallback(true);
									callbackContext.sendPluginResult(progressResult);
								}
							});
						} else {
							_ui.post(new Runnable() {
								@Override
								public void run() {
									Log.d("myApp", "---");
									Toast someToast = Toast.makeText(context,"Failed to scan card. please try again.", Toast.LENGTH_LONG);
									someToast.show();
									PluginResult progressResult = new PluginResult(PluginResult.Status.ERROR,"Failed to scan card. please try again.");
									progressResult.setKeepCallback(true);
									callbackContext.sendPluginResult(progressResult);
								}
							});
						}
					}

					@Override
					public void onDisconnected(SwipeEvent event) {
						Log.d("myApp", "onDisconnected") ;
						//Context context = getApplicationContext();
						Toast someToast = Toast.makeText(context,"Credit card reader is now disconnected", Toast.LENGTH_SHORT);
						someToast.show();
						try {
							//Events.OnBrowserExternalEvent(null, "on disconnect");
						} catch (Exception e) {
							e.printStackTrace();
						}
					}

					@Override
					public void onConnected(SwipeEvent event) {
						Log.d("myApp", "onConnected") ;
						//Context context = getApplicationContext();
						Toast someToast = Toast.makeText(context,"Credit card reader is now connected", Toast.LENGTH_SHORT);
						someToast.show();
						checkDevice();
					}

					@Override
					public void onStarted(SwipeEvent event) {
						Log.d("myApp", "onStarted") ;
					}

					@Override
					public void onStopped(SwipeEvent event) {
						Log.d("myApp", "onStopped") ;
					}
				});
			}
		});
		
		return true;
	}
	
	private void checkDevice1() {
        new Thread(new Runnable() {
            @Override
            public void run()
            {
                Log.d("myApp", "onCheckDevice") ;
                _handler.powerOn();
                if (!_handler.isConnected()) {
                    return;
                }
                if (_handler.isPowerOn())
                    return;
                _handler.powerOn();
            }
        }).start();
    }

    private void checkDevice() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                if (!_handler.isConnected()) {
                    _handler.writeCipherCode("02 08 02");
                    _settings.writeMode(Settings.TYPE_PLAINTEXT);
                    return;
                }
                if (_handler.isPowerOn())
                {
                    _handler.writeCipherCode("02 08 02");
                    _settings.writeMode(Settings.TYPE_PLAINTEXT);
                    return;
                }
                if (_handler.isReadable())
                {
                    _handler.powerOn();
                    _handler.writeCipherCode("02 08 02");
                    _settings.writeMode(Settings.TYPE_PLAINTEXT);
                } else {

                    if (_handler.test() && _handler.isReadable()) {
                        _handler.powerOn();
                        _handler.writeCipherCode("02 08 02");
                        _settings.writeMode(Settings.TYPE_PLAINTEXT);
                    } else {
                        Log.d("myApp", "Didn't Write Anything") ;
                    }
                }
            }
        }).start();
    }


    public void onDestroy() {
        _handler.onDestroy();
        super.onDestroy();
    }
}