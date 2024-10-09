//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Licensed under the MIT License.
//

import UIKit
import AzureCommunicationCalling
import AzureCommunicationUICalling
import AzureCommunicationUIChat

class GroupCallWithChatViewController: UIViewController {
    
    private let groupId = ""
    private let displayName = "USER_NAME"
    private let endpoint = ""
    private let communicationUserId = ""
    private let chatThreadId = ""
    private let userToken = ""
    
    
    private var callComposite: CallComposite?
    private var chatAdapter: ChatAdapter?
    private var chatCompositeViewController: ChatCompositeViewController?
    
    private var startCallButton: UIButton?
    private var endCallButton: UIButton?
    private var connectChatButton: UIButton?
    private var showHideChatButton: UIButton?
    private var chatContainerView: UIView?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground
        initControlBar()
    }

    @objc private func startCallComposite() {
        startCallButton?.isHidden = true
        endCallButton?.isHidden = false
        
        let callCompositeOptions = CallCompositeOptions(
            enableMultitasking: true,
            enableSystemPictureInPictureWhenMultitasking: true,
            displayName: displayName)
        
        let communicationTokenCredential = try! CommunicationTokenCredential(token: userToken)

        let callComposite = self.callComposite ?? CallComposite(credential: communicationTokenCredential, withOptions: callCompositeOptions)
        self.callComposite = callComposite
        
        callComposite.events.onDismissed = { [weak self] callState in
            self?.startCallButton?.isHidden = false
            self?.endCallButton?.isHidden = true
        }
        
        callComposite.launch(locator: .groupCall(groupId: UUID(uuidString: groupId)!))
    }
    
    @objc private func connectChat() {
        let communicationIdentifier = CommunicationUserIdentifier(communicationUserId)
        guard let communicationTokenCredential = try? CommunicationTokenCredential(
            token: userToken) else {
            return
        }

        self.chatAdapter = ChatAdapter(
            endpoint: endpoint,
            identifier: communicationIdentifier,
            credential: communicationTokenCredential,
            threadId: chatThreadId,
            displayName: displayName)

        Task { @MainActor in
            guard let chatAdapter = self.chatAdapter else {
                return
            }
            try await chatAdapter.connect()
        }
        
        self.connectChatButton?.isHidden = true
        self.showHideChatButton?.isHidden = false
    }
    
    @objc private func showHideChat() {
        guard let chatAdapter = self.chatAdapter,
              let chatContainerView = self.chatContainerView else {
            return
        }
        
        if let chatCompositeViewController = self.chatCompositeViewController {
            chatCompositeViewController.willMove(toParent: nil)
            chatCompositeViewController.view.removeFromSuperview()
            chatCompositeViewController.removeFromParent()
            
            self.chatCompositeViewController = nil
        } else {
            let chatCompositeViewController = ChatCompositeViewController(with: chatAdapter)
            
            self.addChild(chatCompositeViewController)
            chatContainerView.addSubview(chatCompositeViewController.view)
            
            chatCompositeViewController.view.translatesAutoresizingMaskIntoConstraints = false
            NSLayoutConstraint.activate([
                chatCompositeViewController.view.topAnchor.constraint(equalTo: chatContainerView.topAnchor),
                chatCompositeViewController.view.bottomAnchor.constraint(equalTo: chatContainerView.bottomAnchor),
                chatCompositeViewController.view.leadingAnchor.constraint(equalTo: chatContainerView.leadingAnchor),
                chatCompositeViewController.view.trailingAnchor.constraint(equalTo: chatContainerView.trailingAnchor)
            ])
            
            chatCompositeViewController.didMove(toParent: self)
            self.chatCompositeViewController = chatCompositeViewController
        }
    }
    
    @objc private func dismissCallComposite() {
        callComposite?.dismiss()
    }
    
    private func initControlBar() {
        let startCallButton = UIButton()
        self.startCallButton = startCallButton
        startCallButton.layer.cornerRadius = 10
        startCallButton.configuration?.contentInsets = NSDirectionalEdgeInsets(top: 6, leading: 16, bottom: 6, trailing: 16)
        startCallButton.backgroundColor = .systemBlue
        startCallButton.setTitle("Call", for: .normal)
        startCallButton.addTarget(self, action: #selector(startCallComposite), for: .touchUpInside)
        startCallButton.translatesAutoresizingMaskIntoConstraints = false
        
        let endCallButton = UIButton(type: .custom)
        self.endCallButton = endCallButton
        endCallButton.layer.cornerRadius = 10
        endCallButton.configuration?.contentInsets = NSDirectionalEdgeInsets(top: 6, leading: 16, bottom: 6, trailing: 16)
        endCallButton.backgroundColor = .systemBlue
        endCallButton.setTitle("End Call", for: .normal)
        endCallButton.addTarget(self, action: #selector(dismissCallComposite), for: .touchUpInside)
        endCallButton.translatesAutoresizingMaskIntoConstraints = false
        endCallButton.isHidden = true
        
        let connectChatButton = UIButton(type: .custom)
        self.connectChatButton = connectChatButton
        connectChatButton.layer.cornerRadius = 10
        connectChatButton.configuration?.contentInsets = NSDirectionalEdgeInsets(top: 6, leading: 16, bottom: 6, trailing: 16)
        connectChatButton.backgroundColor = .systemBlue
        connectChatButton.setTitle("Connect chat", for: .normal)
        connectChatButton.addTarget(self, action: #selector(connectChat), for: .touchUpInside)
        connectChatButton.translatesAutoresizingMaskIntoConstraints = false
        
        let showHideChatButton = UIButton(type: .custom)
        self.showHideChatButton = showHideChatButton
        showHideChatButton.layer.cornerRadius = 10
        showHideChatButton.configuration?.contentInsets = NSDirectionalEdgeInsets(top: 6, leading: 16, bottom: 6, trailing: 16)
        showHideChatButton.backgroundColor = .systemBlue
        showHideChatButton.setTitle("Show/Hide chat", for: .normal)
        showHideChatButton.addTarget(self, action: #selector(showHideChat), for: .touchUpInside)
        showHideChatButton.translatesAutoresizingMaskIntoConstraints = false
        showHideChatButton.isHidden = true
                
        let margin: CGFloat = 32.0
        
        let buttonsContainerView = UIView()
        buttonsContainerView.backgroundColor = .clear
        
        let buttonsStackView = UIStackView(arrangedSubviews: [
            startCallButton,
            endCallButton,
            connectChatButton,
            showHideChatButton])
        buttonsStackView.axis = .horizontal
        buttonsStackView.alignment = .center
        buttonsStackView.distribution = .equalSpacing
        buttonsStackView.spacing = 10
        buttonsStackView.translatesAutoresizingMaskIntoConstraints = false
        buttonsStackView.heightAnchor.constraint(equalToConstant: 50).isActive = true
        
        buttonsContainerView.addSubview(buttonsStackView)

        buttonsContainerView.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            buttonsStackView.topAnchor.constraint(equalTo: buttonsContainerView.topAnchor, constant: 8),
            buttonsStackView.bottomAnchor.constraint(equalTo: buttonsContainerView.bottomAnchor, constant: -8),
            buttonsStackView.leadingAnchor.constraint(equalTo: buttonsContainerView.leadingAnchor, constant: 16),
        ])
        
        let chatContainerView = UIView()
        self.chatContainerView = chatContainerView
        
        let verticalStackView = UIStackView(arrangedSubviews: [
            buttonsContainerView,
            chatContainerView
            ])
        verticalStackView.axis = .vertical
        verticalStackView.alignment = .fill
        verticalStackView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(verticalStackView)
        
        let margins = view.safeAreaLayoutGuide
        let constraints = [
            verticalStackView.leadingAnchor.constraint(equalTo: margins.leadingAnchor),
            verticalStackView.trailingAnchor.constraint(equalTo: margins.trailingAnchor),
            verticalStackView.topAnchor.constraint(equalTo: margins.topAnchor, constant: margin),
            verticalStackView.bottomAnchor.constraint(equalTo: margins.bottomAnchor, constant: -margin)
        ]
        NSLayoutConstraint.activate(constraints)
    }
}
