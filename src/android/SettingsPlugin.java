import org.apache.cordova.CordovaWebView;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaInterface;
import android.util.Log;
import android.widget.Toast;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.imagpay.MessageHandler;
import com.imagpay.Settings;
import com.imagpay.SwipeEvent;
import com.imagpay.SwipeHandler;
import com.imagpay.SwipeListener;

public class SettingsPlugin extends CordovaPlugin {
	public static final String TAG = "Cool Plugin";
	private SwipeHandler _handler;
	private Settings _settings;
	private MessageHandler _msg;
	private Handler _ui;
	private boolean _testFlag = false;
	
	private String _sn, _des, _bdk, _ksn;
	private boolean _plainFlag = false;
	private boolean _desFlag = false;
	private boolean _dukptFlag = false;
	private boolean _snFlag = false;
	/**
	* Constructor.
	*/
	public SettingsPlugin() {
		
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
		Log.v(TAG,"Init SettingsPlugin");
	}
	
	public boolean execute(final String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
		final int duration = Toast.LENGTH_SHORT;
		// Shows a toast
		Log.v(TAG,"SettingsPlugin received:"+ action);
		
		if (action.equals("plainText")) 
        {
            this.plainText();
			// this.writesn();
			// this.readsn();
        }
		if (action.equals("des")) 
        {
            this.des();
        }
		if (action.equals("dukpt")) 
        {
            this.dukpt();
        }
		if (action.equals("readsn")) 
        {
            this.readsn();
        }
		if (action.equals("writesn")) 
        {
            this.writesn();
        }
		if (action.equals("clearparams")) 
        {
            this.clearparams();
        }
		
		cordova.getActivity().runOnUiThread(new Runnable() {
			public void run() {
				_handler = new SwipeHandler(cordova.getActivity().getApplicationContext());
				_settings = new Settings(_handler);
				_ui = new Handler(Looper.myLooper());
				_handler.addSwipeListener(new SwipeListener() {
					@Override
					public void onReadData(SwipeEvent event) {
						Toast someToast = Toast.makeText(cordova.getActivity().getApplicationContext(),"read Data", Toast.LENGTH_SHORT);
						someToast.show();
					}

					@Override
					public void onParseData(SwipeEvent event) {
						Toast someToast = Toast.makeText(cordova.getActivity().getApplicationContext(),"parse Data", Toast.LENGTH_SHORT);
						someToast.show();
						if (_testFlag)
							return;
						String result = event.getValue();
						// hex string message
						sendMessage("Final(16)=>% " + result);
						if (_snFlag && result.startsWith("31 " + _sn)) {
							sendMessage("Written SN successfully!");
							_snFlag = false;
						} else if (_plainFlag && result.startsWith("6f 6b 3f")) {
							sendMessage("Set plain text mode successfully!");
							_plainFlag = false;
						} else if (_desFlag && result.startsWith("6f 6b 3f")) {
							sendMessage("Set 3DES mode successfully!");
							_desFlag = false;
						} else if (_dukptFlag && result.startsWith("6f 6b 3f")) {
							sendMessage("Set DUKPT mode successfully!");
							_dukptFlag = false;
						} else if (_desFlag && result.startsWith("31 " + _des)) {
							_settings.writeMode(Settings.TYPE_3DES);
						} else if (_dukptFlag && result.startsWith("31 " + _bdk + " " + _ksn)) {
							_settings.writeMode(Settings.TYPE_DUKPT);
		//					_settings.writeMode(Settings.TYPE_DUKPT_HSM);
						}
					}

					@Override
					public void onDisconnected(SwipeEvent event) {
						sendMessage("Device is disconnected!");
						Toast toast = Toast.makeText(cordova.getActivity().getApplicationContext(), "Device is disconnected!", duration);
						toast.show();
						toggleConnectStatus();
					}

					@Override
					public void onConnected(SwipeEvent event) {
						sendMessage("Device is connected!");
						Toast toast = Toast.makeText(cordova.getActivity().getApplicationContext(), "Device is connected!", duration);
						toast.show();
						checkDevice();
					}

					@Override
					public void onStarted(SwipeEvent event) {
						if (_testFlag)
							return;
						sendMessage("Device is started");
						Toast toast = Toast.makeText(cordova.getActivity().getApplicationContext(), "Device is started", duration);
						toast.show();
						toggleConnectStatus();
					}

					@Override
					public void onStopped(SwipeEvent event) {
						if (_testFlag)
							return;
						sendMessage("Device is stopped");
						Toast toast = Toast.makeText(cordova.getActivity().getApplicationContext(), "Device is stopped", duration);
						toast.show();
						toggleConnectStatus();
					}
				});
			}
		});
		return true;
	}
	
	private void checkDevice() {
		new Thread(new Runnable() {
			@Override
			public void run() {
				if (!_handler.isConnected()) {
					toggleConnectStatus();
					return;
				}
				if (_handler.isPowerOn()) {
					toggleConnectStatus();
					return;
				}
				if (_handler.isWritable()) {
					sendMessage("Device is ready");
					_handler.powerOn();
				} else {
					_testFlag = false;
					sendMessage("Please wait! testing parameter now");
					if (_handler.test() && _handler.isWritable()) {
						_testFlag = false;
						sendMessage("Device is ready");
						_handler.powerOn();
					} else {
						_testFlag = false;
						sendMessage("Device is not supported or Please close some audio effects(SRS/DOLBY/BEATS/JAZZ/Classic...) and insert device!");
					}
				}
				toggleConnectStatus();
			}
		}).start();
	}
	
	private void toggleConnectStatus() {
		_ui.postDelayed(new Runnable() {
			@Override
			public void run() {
				if (_handler.isConnected() && _handler.isPowerOn()
						&& _handler.isReadable()) {
					// ImageView iv = (ImageView) findViewById(R.id.connect);
					// iv.setVisibility(View.VISIBLE);
					// iv = (ImageView) findViewById(R.id.disconnect);
					// iv.setVisibility(View.INVISIBLE);
				} else {
					// ImageView iv = (ImageView) findViewById(R.id.connect);
					// iv.setVisibility(View.INVISIBLE);
					// iv = (ImageView) findViewById(R.id.disconnect);
					// iv.setVisibility(View.VISIBLE);
				}
			}
		}, 500);
	}
	
	//en
	public void english() {
		// getApp().setLanguage(iMagPayApp.LOCAL_EN);
		// Intent intent = new Intent();
		// intent.setClass(SettingsActivity.this, SettingsActivity.class);
		// intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
		// startActivity(intent);
	}
	
	//cn
	public void onClick() {
		// getApp().setLanguage(iMagPayApp.LOCAL_CN);
		// Intent intent = new Intent();
		// intent.setClass(SettingsActivity.this, SettingsActivity.class);
		// intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
		// startActivity(intent);
	}
	

	//plaintext
	public void plainText() {
		_snFlag = false;
		_plainFlag = true;
		_desFlag = false;
		_dukptFlag = false;
		_settings.writeMode(Settings.TYPE_PLAINTEXT);
		Toast someToast = Toast.makeText(cordova.getActivity().getApplicationContext(),"123123123", Toast.LENGTH_SHORT);
		someToast.show();
	}

	//des
	public void des() {
		_snFlag = false;
		_plainFlag = false;
		_desFlag = true;
		_dukptFlag = false;
		_des = "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd";
		_settings.writeDESKey(_des);
	}

	//dukpt
	public void dukpt() {
		_snFlag = false;
		_plainFlag = false;
		_desFlag = false;
		_dukptFlag = true;
		_bdk = "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd";
		_ksn = "11 22 33 44 55 66 77 00 00 00";
		_settings.writeDUKPTKey(_bdk, _ksn);
	}

	//writesn
	public void writesn() {
		_snFlag = true;
		_plainFlag = false;
		_desFlag = false;
		_dukptFlag = false;
		_sn = "201309300001";
		_sn = _settings.formatSN(_sn);
		sendMessage("Writing SN: " + _sn);
		_settings.writeSN(_sn);
		Toast someToast = Toast.makeText(cordova.getActivity().getApplicationContext(),"Writing SN: " + _sn, Toast.LENGTH_SHORT);
		someToast.show();
		//return "Writing SN: " + _sn;
	}

	//readsn
	public void readsn() {
		sendMessage("SN: " + _settings.getSN());
		Toast someToast = Toast.makeText(cordova.getActivity().getApplicationContext(),"SN: " + _settings.getSN(), Toast.LENGTH_SHORT);
		someToast.show();
		//return "SN: " + _settings.getSN();
	}
	
	//clearparams
	public void clearparams() {
		_handler.powerOff();
		_handler.clearEnvironment();
		checkDevice();
	}
	
	private void sendMessage(String msg) {
		//_msg.sendMessage(msg);
	}
	
	public void onStart() {
		super.onStart();
		checkDevice();
	}

	public void onStop() {
		_handler.powerOff();
		super.onStop();
	}

	public void onDestroy() {
		_handler.onDestroy();
		super.onDestroy();
	}
}